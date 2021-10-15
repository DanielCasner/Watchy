#pragma once

#include "TimeScreen.h"

class MainScreen : public TimeScreen {
 private:
  static uint8_t internetSynced;
  static int8_t internetData[6];

 public:
  MainScreen(uint16_t bg = GxEPD_WHITE);
  void show() override;
};
