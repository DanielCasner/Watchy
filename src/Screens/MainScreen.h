#pragma once

#include "TimeScreen.h"

class MainScreen : public TimeScreen {
 private:
  static uint8_t sunrise;
  static uint8_t sunset;
  static  int8_t daily_max_temp;
  static  int8_t daily_min_temp;
  static uint8_t flags;

  void getWeatherData();
  void drawWeatherData();

 public:
  MainScreen(uint16_t bg = GxEPD_WHITE);
  void show() override;
};
