#include "weatherreport.h"

std::string reportWeather(WeatherSensor* sensor) {
    float temp = sensor->getTemperature();
    bool rain = sensor->isRaining();

    if (rain)
        return "Rainy";
    else if (temp > 30)
        return "Hot";
    else if (temp <= 30)
        return "Cold";  // ❌ BUG: should handle exactly 30 separately
    return "Unknown";
}
