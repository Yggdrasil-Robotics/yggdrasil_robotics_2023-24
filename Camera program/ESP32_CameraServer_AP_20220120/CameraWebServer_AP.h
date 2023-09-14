#ifndef _CameraWebServer_AP_H
#define _CameraWebServer_AP_H
#include "esp_camera.h"
#include <WiFi.h>

class CameraWebServer_AP {
  public:
    void CameraWebServer_AP_Init(void);
    String wifi_name;

  private:
    // const char *ssid = "ESP32_CAM";
    // const char *password = "elegoo2020";
    char *ssid = "ELEGOO-";
    //char *password = "elegoo2020";
    char *password = "elegoo2020uah";
};

#endif
