#include <iostream>
#include <string>
#include <cassert>

namespace WeatherSpace
{
    class IWeatherSensor {
    public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
        virtual ~IWeatherSensor() {}
    };

    class SensorStub : public IWeatherSensor {
    public:
        double TemperatureInC() const override { return 26; }
        int Precipitation() const override { return 70; }
        int Humidity() const override { return 72; }
        int WindSpeedKMPH() const override { return 52; }
    };

    std::string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        std::string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }

    // Bug-exposing stub
    class RainySensorStub : public IWeatherSensor {
    public:
        double TemperatureInC() const override { return 28; }
        int Precipitation() const override { return 80; } // high precipitation
        int Humidity() const override { return 70; }
        int WindSpeedKMPH() const override { return 30; } // low wind
    };

    void TestRainy()
    {
        RainySensorStub sensor;
        std::string report = Report(sensor);
        std::cout << report << std::endl;
        assert(report.find("rain") != std::string::npos); // will fail
    }

    void TestHighPrecipitation()
    {
        SensorStub sensor;
        std::string report = Report(sensor);
        assert(report.length() > 0);
    }
}

void testWeatherReport()
{
    std::cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    std::cout << "All is well (maybe!)\n";
}
