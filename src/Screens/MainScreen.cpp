#include "MainScreen.h"

#include <stdlib.h>
#include <time.h>

#include "OptimaLTStd22pt7b.h"
#include "OptimaLTStd7pt7b.h"
#include "OptimaLTStd_Black32pt7b.h"
#include "GetLocation.h"
#include "SyncTime.h"

using namespace Watchy;

RTC_DATA_ATTR uint8_t MainScreen::internetSynced;
RTC_DATA_ATTR int8_t MainScreen::internetData[6];

MainScreen::MainScreen(uint16_t bg) : TimeScreen(bg) {
    internetSynced = false;
    memset(internetData, -1, sizeof(internetData));
}

void MainScreen::show() {
  tm t;
  time_t tt = now();
  localtime_r(&tt, &t);

  if (internetSynced == true && t.tm_hour == 5 && t.tm_min == 0) internetSynced = false;

  if (internetSynced == false) {
    Watchy_SyncTime::syncTime(Watchy_GetLocation::currentLocation.timezone);
    Watchy::sensor.resetStepCounter();
    internetSynced = true;
  }

  TimeScreen::show();
  display.setCursor(0, 100);
  display.printf("%d F\n%d F\n%d:%d\n%d:%d", internetData[0],
                                             internetData[1],
                                             internetData[2],
                                             internetData[3],
                                             internetData[4],
                                             internetData[5]);
}
