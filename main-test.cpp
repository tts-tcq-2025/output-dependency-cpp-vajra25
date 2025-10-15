#include "gtest/gtest.h"

// Declare test functions
void testTshirtSize();
void testPrintColorMap();
void testWeatherReport();

TEST(TShirt, Size) {
    testTshirtSize();
}

TEST(ColorMap, Print) {
    testPrintColorMap();
}

TEST(WeatherReport, Report) {
    testWeatherReport();
}

