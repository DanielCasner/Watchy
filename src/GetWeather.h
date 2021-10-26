#pragma once

#include "Watchy.h"

namespace Watchy_GetWeather {

constexpr const char* OPENWEATHERMAP_APIKEY =
    "d1eadfe282a5f045f85620991eb1369e";  // use your own API key :)
constexpr const char* OPENWEATHERMAP_URL =
    "http://api.openweathermap.org/data/2.5/weather";
constexpr const char* TEMP_UNIT = "imperial";  // use "imperial" for Fahrenheit"
const int WEATHER_UPDATE_INTERVAL = 30 * 60 * 1000;  // 30 minutes in millis

typedef struct weatherData {
  int8_t temperature;
  int16_t weatherConditionCode;
  char weatherCity[25];
} weatherData;

extern weatherData getWeather();
extern time_t lastGetWeatherTS; // timestamp of last successful getWeather call

}  // namespace Watchy_GetWeather
