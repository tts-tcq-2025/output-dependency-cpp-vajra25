#include <iostream>
#include <cassert>
#include "tshirts.h"
#include "misaligned.h"
#include "weatherreport.h"

// ---------- TEST FUNCTIONS ----------

void testTshirt() {
    std::cout << "Testing T-shirt classification...\n";
    assert(tshirtSize(35) == "S");
    assert(tshirtSize(37) == "M");
    // 🧨 Stronger boundary test - should FAIL (exposes bug)
    assert(tshirtSize(36) == "M");
}

void testMisaligned() {
    std::cout << "Testing color code mapping...\n";
    assert(getColorForNumber(2) == "Red");
    assert(getColorForNumber(9) == "White");
    // 🧨 Stronger boundary test
    assert(getColorForNumber(10) == "Invalid");
}

void testWeatherReport() {
    std::cout << "Testing weather reporting...\n";

    StubSensorHot hot;
    StubSensorRain rain;

    assert(reportWeather(&rain) == "Rainy");
    assert(reportWeather(&hot) == "Hot");

    // 🧨 Stronger boundary test to expose temp=30 bug
    class Stub30 : public WeatherSensor {
    public:
        float getTemperature() override { return 30.0; }
        bool isRaining() override { return false; }
    } sensor30;

    assert(reportWeather(&sensor30) == "Moderate");
}

// ---------- MAIN ----------

int main() {
    std::cout << "Running tests...\n";

    testTshirt();
    testMisaligned();
    testWeatherReport();

    std::cout << "✅ All tests passed (if you see this, it’s a false pass!)\n";
    return 0;
}

