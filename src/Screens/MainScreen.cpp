#include "MainScreen.h"

#include <stdlib.h>
#include <time.h>

#include "OptimaLTStd22pt7b.h"
#include "OptimaLTStd7pt7b.h"
#include "OptimaLTStd_Black32pt7b.h"
#include "GetLocation.h"
#include "SyncTime.h"

using namespace Watchy;

RTC_DATA_ATTR uint8_t MainScreen::sunrise;
RTC_DATA_ATTR uint8_t MainScreen::sunset;
RTC_DATA_ATTR  int8_t MainScreen::daily_max_temp;
RTC_DATA_ATTR  int8_t MainScreen::daily_min_temp;
RTC_DATA_ATTR uint8_t  MainScreen::flags;

#define isWeatherSynced()    (flags &&  0x01)
#define setWeatherSynced()   (flags |=  0x01)
#define clearWeatherSynced() (flags &= ~0x01)
#define isWeatherAlert()     (flags &&  0x02)
#define setWeatherAlert()    (flags |=  0x02)
#define clearWeatherAlert()  (flags &= ~0x02);


#define K2F(K) ((K-273)*1.8)

MainScreen::MainScreen(uint16_t bg) : TimeScreen(bg), weather_synced(false) {
}

void MainScreen::getWeatherData() {

}

void MainScreen::drawWeatherData() {
    display.printf("%d F\n%d F\n%d:%d\n%d:%d\n%s",
                   daily_max_temp,
                   daily_min_temp,
                   sunrise >> 4,
                   sunrise & 0xF,
                   sunset >> 4;
                   sunset & 0xF,
                   weather_alert ? "alert" : "");
}

void MainScreen::show() {
  tm t;
  time_t tt = now();
  localtime_r(&tt, &t);

  if (weather_synced == true && t.tm_hour == 5 && t.tm_min == 0) weather_synced = false;

  if (weather_synced == false) getWeatherData();

  TimeScreen::show();
  if (weather_synced == true) {
      display.setCursor(0, 120);
      drawWeatherData();

}
