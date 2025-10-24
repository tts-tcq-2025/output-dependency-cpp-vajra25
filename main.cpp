#include <iostream>
#include <cassert>
#include "tshirts.h"
#include "misaligned.h"
#include "weatherreport.h"

void testTshirt() {
    std::cout << "Testing T-shirt classification...\n";
    assert(tshirtSize(35) == "S");
    assert(tshirtSize(36) == "S");
    assert(tshirtSize(38) == "M");
    assert(tshirtSize(40) == "M");
    assert(tshirtSize(41) == "L");
}

void testMisaligned() {
    std::cout << "Testing color code mapping...\n";
    assert(getColorForNumber(0) == "Black");
    assert(getColorForNumber(5) == "Green");
    assert(getColorForNumber(9) == "White");
    assert(getColorForNumber(10) == "Invalid");
}

void testWeatherReport() {
    std::cout << "Testing weather reporting...\n";

    StubSensorHot hot;
    StubSensorRain rain;
    StubSensorModerate moderate;

    assert(reportWeather(&hot) == "Hot");
    assert(reportWeather(&rain) == "Rainy");
    assert(reportWeather(&moderate) == "Moderate");
}

int main() {
    std::cout << "Running all tests...\n";

    testTshirt();
    testMisaligned();
    testWeatherReport();

    std::cout << "✅ All tests passed successfully!\n";
    return 0;
}
