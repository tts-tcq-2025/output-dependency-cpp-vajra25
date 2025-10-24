#include <iostream>
#include "tshirts.h"
#include "misaligned.h"
#include "weatherreport.h"

bool testTshirt() {
    return tshirtSize(35) == "S" &&
           tshirtSize(36) == "S" &&
           tshirtSize(38) == "M" &&
           tshirtSize(40) == "M" &&
           tshirtSize(41) == "L";
}

bool testMisaligned() {
    return getColorForNumber(0) == "Black" &&
           getColorForNumber(5) == "Green" &&
           getColorForNumber(9) == "White" &&
           getColorForNumber(10) == "Invalid";
}

bool testWeatherReport() {
    StubSensorHot hot;
    StubSensorRain rain;
    StubSensorModerate moderate;

    return reportWeather(&hot) == "Hot" &&
           reportWeather(&rain) == "Rainy" &&
           reportWeather(&moderate) == "Moderate";
}

int main() {
    std::cout << "Running all tests...\n";

    bool tshirtOK = testTshirt();
    bool colorOK = testMisaligned();
    bool weatherOK = testWeatherReport();

    if (tshirtOK && colorOK && weatherOK) {
        std::cout << "✅ All tests passed successfully!\n";
        return 0; // success exit
    } else {
        std::cout << "❌ One or more tests failed!\n";
        if (!tshirtOK) std::cout << "   - Tshirt tests failed\n";
        if (!colorOK) std::cout << "   - Misaligned tests failed\n";
        if (!weatherOK) std::cout << "   - WeatherReport tests failed\n";
        return 1; // failure exit
    }
}
