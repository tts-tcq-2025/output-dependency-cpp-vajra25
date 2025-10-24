#include <string>
using namespace std;

class WeatherSensor {
public:
    virtual float getTemperature() { return 25.0; }  // default
};

class WeatherReporter {
    WeatherSensor* sensor;
public:
    explicit WeatherReporter(WeatherSensor* s) : sensor(s) {}
    string reportWeather() {
        float temp = sensor->getTemperature();
        if (temp < 0) return "Freezing";
        else if (temp < 20) return "Cold";
        else if (temp < 35) return "Warm";
        else return "Hot";
    }
};
