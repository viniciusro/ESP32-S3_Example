#include <Arduino.h>
#include <Waveshare_ST7262_LVGL.h>
#include <lvgl.h>
#include "ui.h"
#include "vars.h"
#include "screens.h"
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

#define MVG_TICK_INTERVAL_MS 30000
#define JSON_TICK_INTERVAL_MS 5000
#define UDP_TICK_INTERVAL_MS 1000
#define UDP_PORT 12345

uint8_t cpuTempUdp = 0;
uint8_t cpuUsageUdp = 0;
uint8_t cpuPowerDrawPackageUdp = 0;
uint16_t cpuFrequencyUdp = 0;
uint8_t gpuTempUdp = 0;
uint8_t gpuUsageUdp = 0;
uint16_t gpuCoreFrequencyUdp = 0;
uint16_t gpuMemoryFrequencyUdp = 0;
uint8_t ramUsageUdp = 0;
uint8_t hddUsage_0Udp = 0;
uint8_t hddUsage_1Udp = 0;
uint8_t hddUsage_2Udp = 0;
float valueEtf_0;
float quoteEtf_0;
float valueEtf_1;
float quoteEtf_1;
float valueEtf_2;
float quoteEtf_2;
float valueEtf_3;
float quoteEtf_3;
float valueEtf_4;
float quoteEtf_4;
float valueEtf_5;
float quoteEtf_5;

uint8_t alive_counter = 0;

//NTP
#define NTP_OFFSET 3600         // 3600 or 7200        // In seconds
#define NTP_INTERVAL 60 * 1000  // In miliseconds
#define NTP_ADDRESS "europe.pool.ntp.org"
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, 0, NTP_INTERVAL);
unsigned long epochTime;
uint8_t currentHours = 0;
uint8_t currentMinutes = 0;
int currentDay = 0;
int currentMonth = 0;
int currentYear = 0;

// JSON
const String urlHost = "http://api.openweathermap.org/data/2.5/forecast?q=Munich,DE&APPID=0fed462cf5c624f21f1ee846785a44ec&mode=json&units=metric&cnt=1";
HTTPClient httpClient1;  // Separate instance for weather request
HTTPClient httpClient2;  // Separate instance for U-Bahn request
WiFiClient espClient;
char weatherMain[12];
char weatherDescription[25];
float list_0_main_temp;
int list_0_main_humidity;
float list_0_wind_speed;
int city_timezone;

const char *mvgApiUrl = "https://www.mvg.de/api/fib/v2/departure?globalId=de:09162:340&limit=3&offsetInMinutes=0&transportTypes=UBAHN,SCHIFF";
//const String mvgApiUrl = "http://www.mvg.de/api/fib/v2/departure?globalId=de:09162:340&limit=3&offsetInMinutes=0&transportTypes=UBAHN,SCHIFF";
const char *destination;
int platform;
long long plannedDepartureTime;
unsigned long epcohTimeMvg;
uint8_t departure = 0;

// UDP
WiFiUDP udp;
const char *ssid = "XXX";         // Replace with your WiFi SSID
const char *password = "XXX";  // Replace with your WiFi password

int isOn = 0;

void udpUpdate(void *pvParameters);
TaskHandle_t udpUpdateTask;

void jsonUpdate(void *pvParameters);
TaskHandle_t jsonUpdateTask;

void mvgUpdate(void *pvParameters);
TaskHandle_t mvgUpdateTask;

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char *buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

void setCalendarDate(int year, int month, int day);
//void parsingJson();
void parsingJson(String input);
void epcohSync();
void setupWiFi();
void parseUDPData(const String &data);
void Udp_ReceiveParse(void);
void check_active_screen();
void update_label(lv_obj_t *label, int value);
void update_label_text(lv_obj_t *label, int value, const char *pre_text, const char *pos_text);
void update_label_float(lv_obj_t *label, float value, const char *pre_text, const char *pos_text);
void deserializeMvgApi(String input);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  //setupWiFi();
  delay(5000);

  Serial.println("Initialize display and touchscreen");
  lcd_init();
  Serial.println("Create UI");

  /* Lock the mutex due to the LVGL APIs are not thread-safe */
  lvgl_port_lock(-1);
  /* EEZ Flow UI */
  ui_init();
  /* Release the mutex */
  lvgl_port_unlock();

  /**
     * You can use toggle_backlight function to toggle lcd backlight
     * It uses IO Expander to write HIGH or LOW value based on isOn and toggles isOn value as well
     */
  // toggle_backlight(int &isOn);

  xTaskCreatePinnedToCore(
    udpUpdate,       // Function to implement the task
    "udpUpdate",     // Name of the task
    9216,            // Stack size in bytes
    NULL,            // Task input parameter
    1,               // Priority of the task
    &udpUpdateTask,  // Task handle.
    1                // Core where the task should run
  );

  xTaskCreatePinnedToCore(
    jsonUpdate,       // Function to implement the task
    "jsonUpdate",     // Name of the task
    9216,             // Stack size in bytes
    NULL,             // Task input parameter
    1,                // Priority of the task
    &jsonUpdateTask,  // Task handle.
    1                 // Core where the task should run
  );

  xTaskCreatePinnedToCore(
    mvgUpdate,       // Function to implement the task
    "mvgUpdate",     // Name of the task
    4096,            // Stack size in bytes
    NULL,            // Task input parameter
    1,               // Priority of the task
    &mvgUpdateTask,  // Task handle.
    1                // Core where the task should run
  );
}

void loop() {
#if LV_USE_LOG != 0
  lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif
}

void mvgUpdate(void *pvParameters) {
  for (;;) {
    //  Check WiFi Status
    if (WiFi.status() == WL_CONNECTED) {
      // ---- MVG API (UBAHN) REQUEST ----
      httpClient2.setTimeout(5000);  // Set a timeout of 5 seconds
      //httpClient2.begin(espClient, mvgApiUrl);  // MVG API URL
      httpClient2.begin(mvgApiUrl);
      httpClient2.addHeader("User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");
      //httpClient2.addHeader("Content-Type", "application/json");
      int httpCode2 = httpClient2.GET();

      // Check the HTTP return code for MVG API
      if (httpCode2 == 200) {
        // Parse JSON U-Bahn data
        deserializeMvgApi(httpClient2.getString());
      } else {
        Serial.println("Error on U-Bahn HTTP request");
        Serial.println(httpCode2);
      }
      httpClient2.end();  // Close the U-Bahn connection

      lvgl_port_lock(-1);
      update_label_text(objects.departure_time, departure, "Depart in: ", " Minutes");
      //lv_label_set_text(objects.destination, destination);
      update_label_text(objects.platform, platform, "Platform: ", "");
      lvgl_port_unlock();
    }
    // Delay to control the loop frequency
    vTaskDelay(pdMS_TO_TICKS(MVG_TICK_INTERVAL_MS));
  }
}

void jsonUpdate(void *pvParameters) {
  for (;;) {
    //  Check WiFi Status
    if (WiFi.status() == WL_CONNECTED) {
      // ---- CLIMA REQUEST ----
      httpClient1.setTimeout(5000);           // Set a timeout of 5 seconds
      httpClient1.begin(espClient, urlHost);  // Weather API URL
      int httpCode1 = httpClient1.GET();

      // Check the HTTP return code for weather API
      if (httpCode1 > 0) {
        // Parse JSON weather data
        parsingJson(httpClient1.getString());
      } else {
        Serial.println("Error on Weather HTTP request");
      }
      httpClient1.end();  // Close the weather connection

      epcohSync(); /* read NTP server time*/

      // Create a buffer to hold the formatted string
      char bufferTime[4];  // 2 digits + null terminator, "01" -> 3 characters

      lvgl_port_lock(-1);

      update_label_text(objects.temperature, list_0_main_temp, "Temperature: ", " °C");
      update_label_text(objects.humidity, list_0_main_humidity, "Humidity: ", " %");
      update_label_text(objects.wind_speed, list_0_wind_speed, "Speed: ", " m/s");
      sprintf(bufferTime, "%02d", currentHours);  // Format the value with leading zero
      lv_label_set_text(objects.hours, bufferTime);
      sprintf(bufferTime, "%02d", currentMinutes);  // Format the value with leading zero
      lv_label_set_text(objects.minutes, bufferTime);
      lv_label_set_text(objects.clima_description, weatherDescription);
      lv_label_set_text(objects.clima_main, weatherMain);
      setCalendarDate(currentYear, currentMonth, currentDay);

      lvgl_port_unlock();
    }
    // Delay to control the loop frequency
    vTaskDelay(pdMS_TO_TICKS(JSON_TICK_INTERVAL_MS));
  }
}

void udpUpdate(void *pvParameters) {
  // Connect to Wi-Fi
  setupWiFi();

  // Get the IP address as a string
  String ipAddress = WiFi.localIP().toString();
  // Convert String to a C-style string for LVGL
  const char *ipChar = ipAddress.c_str();
  lv_label_set_text(objects.ip_text, ipChar);

  for (;;) {
    lvgl_port_lock(-1);

    Udp_ReceiveParse();

    lvgl_port_unlock();

    if (alive_counter > 15) {
      alive_counter = 0;
    }

    // Delay to control the loop frequency
    vTaskDelay(pdMS_TO_TICKS(UDP_TICK_INTERVAL_MS));
  }
}

// JSON6
void parsingJson(String input) {

  // String input;
  StaticJsonDocument<1536> doc;

  DeserializationError error = deserializeJson(doc, input);

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  JsonObject list_0 = doc["list"][0];
  JsonObject list_0_main = list_0["main"];
  list_0_main_temp = list_0_main["temp"];          // 12.44
  list_0_main_humidity = list_0_main["humidity"];  // 90

  JsonObject list_0_weather_0 = list_0["weather"][0];
  const char *list_0_weather_0_main = list_0_weather_0["main"];                // "Clouds"
  const char *list_0_weather_0_description = list_0_weather_0["description"];  // "overcast clouds"
  strcpy(weatherMain, list_0_weather_0_main);
  strcpy(weatherDescription, list_0_weather_0_description);

  JsonObject list_0_wind = list_0["wind"];
  list_0_wind_speed = list_0_wind["speed"];  // 1.78

  JsonObject city = doc["city"];
  city_timezone = city["timezone"];  // 7200
}

/*
// JSON5
void parsingJson() {
  const size_t capacity = 2 * JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 3 * JSON_OBJECT_SIZE(3) + 160;
  DynamicJsonBuffer jsonBuffer(capacity);

  JsonObject &root = jsonBuffer.parseObject(http.getString());

  JsonObject &list_0 = root["list"][0];
  long list_0_dt = list_0["dt"];  // 1612029600

  float list_0_main_temp = list_0["main"]["temp"];  // 4.34

  JsonObject &list_0_weather_0 = list_0["weather"][0];
  int list_0_weather_0_id = list_0_weather_0["id"];                            // 500
  const char *list_0_weather_0_main = list_0_weather_0["main"];                // "Rain"
  const char *list_0_weather_0_description = list_0_weather_0["description"];  // "light rain"

  JsonObject &city = root["city"];
  int city_timezone = city["timezone"];  // 3600
  long city_sunrise = city["sunrise"];   // 1611989061
  long city_sunset = city["sunset"];     // 1612022970

  temp = list_0_main_temp;
  strcpy(weatherDescription, list_0_weather_0_description);
}
*/
void epcohSync() {
  timeClient.update();
  epochTime = timeClient.getEpochTime() + NTP_OFFSET;  // Add the offset manually
  currentHours = hour(epochTime);
  currentMinutes = minute(epochTime);

  time_t rawTime = (time_t)epochTime;  // Cast epoch time to time_t
  tm *timeinfo = gmtime(&rawTime);     // Get structured time

  // Extract day, month, and year
  currentDay = timeinfo->tm_mday;
  currentMonth = timeinfo->tm_mon + 1;     // tm_mon is 0-indexed, so add 1
  currentYear = timeinfo->tm_year + 1900;  // tm_year is years since 1900, so add 1900
}

void setupWiFi() {
  // Connect to Wi-Fi
  //WiFi.mode(WIFI_MODE_STA);
  WiFi.mode(WIFI_STA);
  WiFi.setSleep(false);  // Disable Wi-Fi power-saving mode
  WiFi.begin(ssid, password);
  int timeout = 0;

  while (WiFi.status() != WL_CONNECTED) {
    delay(50);
    Serial.print(".");
    timeout++;
    if (timeout > 5000) {
      Serial.print("ESP.restart");
      ESP.restart();  // Reset the ESP32 if not connected within the timeout
    }
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Initialize UDP
  udp.begin(UDP_PORT);
  Serial.println("udp.begin");

  timeClient.begin();
}

// Parse Incoming UDP Data
void parseUDPData(const String &data) {
  // Split the data string by commas
  int index = 0;
  String tempStr = "";
  String tempData = data;
  //Serial.println(data);

  while (tempData.length() > 0) {
    int commaIndex = tempData.indexOf('|');
    if (commaIndex == -1) {
      commaIndex = tempData.length();
    }

    tempStr = tempData.substring(0, commaIndex);
    tempData = tempData.substring(commaIndex + 1);

    int32_t value = tempStr.toInt();

    switch (index) {
      case 0:
        cpuTempUdp = value;
        break;
      case 1:
        cpuUsageUdp = value;
        break;
      case 2:
        cpuPowerDrawPackageUdp = value;
        break;
      case 3:
        cpuFrequencyUdp = value;
        break;
      case 4:
        gpuTempUdp = value;
        break;
      case 5:
        gpuUsageUdp = value;
        break;
      case 6:
        gpuCoreFrequencyUdp = value;
        break;
      case 7:
        gpuMemoryFrequencyUdp = value;
        break;
      case 8:
        ramUsageUdp = value;
        break;
      case 9:
        hddUsage_0Udp = value;
        break;
      case 10:
        hddUsage_1Udp = value;
        break;
      case 11:
        hddUsage_2Udp = value;
        break;
      case 12:
        valueEtf_0 = tempStr.toFloat();
        break;
      case 13:
        quoteEtf_0 = tempStr.toFloat();
        break;
      case 14:
        valueEtf_1 = tempStr.toFloat();
        break;
      case 15:
        quoteEtf_1 = tempStr.toFloat();
        break;
      case 16:
        valueEtf_2 = tempStr.toFloat();
        break;
      case 17:
        quoteEtf_2 = tempStr.toFloat();
        break;
      case 18:
        valueEtf_3 = tempStr.toFloat();
        break;
      case 19:
        quoteEtf_3 = tempStr.toFloat();
        break;
      case 20:
        valueEtf_4 = tempStr.toFloat();
        break;
      case 21:
        quoteEtf_4 = tempStr.toFloat();
        break;
      case 22:
        valueEtf_5 = tempStr.toFloat();
        break;
      case 23:
        quoteEtf_5 = tempStr.toFloat();
        break;
      default:
        break;
    }
    index++;
  }
}

void Udp_ReceiveParse(void) {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char packetBuffer[255];
    int len = udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;  // Null-terminate the packet buffer
    }
    String data(packetBuffer);
    // Parse the received data
    parseUDPData(data);

    check_active_screen();
  }
}

void update_label(lv_obj_t *label, int value) {
  char buf[64];
  snprintf(buf, sizeof(buf), "%d", value);
  lv_label_set_text(label, buf);
}

void update_label_text(lv_obj_t *label, int value, const char *pre_text, const char *pos_text) {
  char buf[128];
  snprintf(buf, sizeof(buf), "%s%d%s", pre_text, value, pos_text);
  lv_label_set_text(label, buf);
}

void update_label_float(lv_obj_t *label, float value, const char *pre_text, const char *pos_text) {
  char buf[512];

  if (value == 0.0f) {
    // Handle the case where value is 0.0
    snprintf(buf, sizeof(buf), "%s%s%s", pre_text, "N/A", pos_text);  // Show "N/A" when value is 0
  } else {
    // Handle the normal case with a valid float value
    snprintf(buf, sizeof(buf), "%s%.2f%s", pre_text, value, pos_text);  // Format float with 2 decimal places
  }

  lv_label_set_text(label, buf);
}

void check_active_screen() {
  // Get the currently active screen
  lv_obj_t *active_screen = lv_scr_act();

  if (active_screen == objects.main) {
    /* CPU */
    update_label_text(objects.cpu_temperature_c, cpuTempUdp, "", "°C");
    update_label_text(objects.cpu_load, cpuUsageUdp, "", "%");
    lv_arc_set_value(objects.cpu_load_arc, cpuUsageUdp);
    update_label_text(objects.cpu_freq_mhz, cpuFrequencyUdp, "", "MHz");
    lv_bar_set_value(objects.cpu_temp_bar, cpuTempUdp, LV_ANIM_ON);
    lv_bar_set_value(objects.cpu_clock_bar, cpuFrequencyUdp, LV_ANIM_ON);

    /* GPU */
    update_label_text(objects.gpu_temperature, gpuTempUdp, "", "°C");
    update_label_text(objects.gpu_load, gpuUsageUdp, "", "%");
    lv_arc_set_value(objects.gpu_load_arc, gpuUsageUdp);
    update_label_text(objects.gpu_freq_mhz, gpuCoreFrequencyUdp, "", "MHz");
    lv_bar_set_value(objects.gpu_temp_bar, gpuTempUdp, LV_ANIM_ON);
    lv_bar_set_value(objects.gpu_clock_bar, gpuUsageUdp, LV_ANIM_ON);

    /* RAM */
    update_label_text(objects.mem_load, ramUsageUdp, "", "%");
    lv_arc_set_value(objects.ram_load_arc, ramUsageUdp);

    /* HDD */
    update_label_text(objects.hdd0_usage, hddUsage_0Udp, "", "%");
    update_label_text(objects.hdd1_usage, hddUsage_1Udp, "", "%");
    update_label_text(objects.hdd2_usage, hddUsage_2Udp, "", "%");

    lv_bar_set_value(objects.hdd0_usage_bar, hddUsage_0Udp, LV_ANIM_ON);
    lv_bar_set_value(objects.hdd1_usage_bar, hddUsage_1Udp, LV_ANIM_ON);
    lv_bar_set_value(objects.hdd2_usage_bar, hddUsage_2Udp, LV_ANIM_ON);

    //EUWAX Gold II
    update_label_float(objects.value_etf_0, valueEtf_0, "Price: ", "$");
    update_label_float(objects.quote_etf_0, quoteEtf_0, "Performance: ", "%");
    //iShares Core MSCI World
    update_label_float(objects.value_etf_1, valueEtf_1, "Price: ", "$");
    update_label_float(objects.quote_etf_1, quoteEtf_1, "Performance: ", "%");
    //Vanguard FTSE All-World
    update_label_float(objects.value_etf_3, valueEtf_4, "Price: ", " $");
    update_label_float(objects.quote_etf_3, quoteEtf_4, "Performance: ", "%");
    //iShares MSCI Global Semiconductors
    update_label_float(objects.value_etf_2, valueEtf_2, "Price: ", "$");
    update_label_float(objects.quote_etf_2, quoteEtf_2, "Performance: ", "%");
    //iShares STOXX Europe 600
    update_label_float(objects.value_etf_4, valueEtf_3, "Price: ", "$");
    update_label_float(objects.quote_etf_4, quoteEtf_3, "Performance: ", "%");
    //Xtrackers Artificial Intelligence
    update_label_float(objects.value_etf_5, valueEtf_5, "Price: ", "$");
    update_label_float(objects.quote_etf_5, quoteEtf_5, "Performance: ", "%");

    float total_performance = quoteEtf_0 + quoteEtf_1 + quoteEtf_2 + quoteEtf_3 + quoteEtf_4 + quoteEtf_5;
    update_label_float(objects.total_performance, total_performance, "Total Performance: ", "%");

    update_label(objects.alive_udp, alive_counter++);

  } else {
    printf("Unknown screen is active.\n");
  }
}

// Function to set the calendar's date, month, and year
void setCalendarDate(int year, int month, int day) {
  // Set the current date as "today"
  lv_calendar_set_today_date(objects.calendar, year, month, day);

  // Optionally, set the displayed month/year
  lv_calendar_set_showed_date(objects.calendar, year, month);
}

//JSON5
/*
void deserializeMvgApi(String input) {
  // Create a StaticJsonBuffer object with a defined size
  StaticJsonBuffer<3072> jsonBuffer; // Adjust the size based on your JSON data

  // Parse the JSON input
  JsonArray& root = jsonBuffer.parseArray(input);

  // Check for parsing errors
  if (!root.success()) {
    Serial.println("Failed to parse JSON");
    return;
  }

  // Loop through the JSON array
  for (JsonObject& item : root) {
    long plannedDepartureTime = item["plannedDepartureTime"];  // 1699207020000, 1699207380000, ...
    const char* destination = item["destination"];  // "Moosach", "Fürstenried West", ...
    int platform = item["platform"];  // 1, 2, 1, 2

    if (platform == 2) { // Check for platform 2
      long epochTimeMvg = plannedDepartureTime / 1000;  // Convert ms to s
      calculateTimeDifferenceMinutes(epochTimeMvg, epochTime); // Call your time difference function
      break;  // Exit the loop if platform 2 is found
    } else {
      // Optionally handle other platforms
      // Serial.println("Other platform");
    }
  }
}
*/

//JSON6
void deserializeMvgApi(String input) {
  // String input;

  DynamicJsonDocument doc(3072);

  DeserializationError error = deserializeJson(doc, input);

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  for (JsonObject item : doc.as<JsonArray>()) {

    plannedDepartureTime = item["plannedDepartureTime"];  // 1699207020000, 1699207380000, ...
    destination = item["destination"];                    // "Moosach", "Fürstenried West", "Moosach", "Fürstenried ...
    platform = item["platform"];                          // 1, 2, 1, 2
    if (platform == 2)                                    //"Fürstenried West"
    {
      epcohTimeMvg = plannedDepartureTime / 1000;  // convert ms to s
      departure = minute(epcohTimeMvg) - currentMinutes;

      if (minute(epcohTimeMvg) > currentMinutes) {
        departure = minute(epcohTimeMvg) - currentMinutes;
      } else {
        departure = currentMinutes - minute(epcohTimeMvg);
      }
      break;
    } else {
      //Serial.println("outro");
    }
  }
}
