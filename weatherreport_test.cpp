#include <cassert>
#include "weatherreport.cpp"

class StubSensorHot : public WeatherSensor {
public:
    float getTemperature() override { return 40.0; }
};

class StubSensorCold : public WeatherSensor {
public:
    float getTemperature() override { return 10.0; }
};

class StubSensorFreezing : public WeatherSensor {
public:
    float getTemperature() override { return -5.0; }
};

void testWeatherReport() {
    StubSensorCold cold;
    WeatherReporter wr1(&cold);
    assert(wr1.reportWeather() == "Cold");

    StubSensorHot hot;
    WeatherReporter wr2(&hot);
    assert(wr2.reportWeather() == "Hot");

    StubSensorFreezing freeze;
    WeatherReporter wr3(&freeze);
    assert(wr3.reportWeather() == "Freezing");
}
