#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <string>

class WeatherSensor {
public:
    virtual float getTemperature() = 0;
    virtual bool isRaining() = 0;
    virtual ~WeatherSensor() = default;
};

class StubSensorHot : public WeatherSensor {
public:
    float getTemperature() override { return 45.0; } // simulate hot
    bool isRaining() override { return false; }
};

class StubSensorRain : public WeatherSensor {
public:
    float getTemperature() override { return 25.0; }
    bool isRaining() override { return true; }
};

std::string reportWeather(WeatherSensor* sensor);

#endif
