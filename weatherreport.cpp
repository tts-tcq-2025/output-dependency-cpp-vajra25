#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
    public:
        virtual double TemperatureInC() const = 0;
        virtual int Precipitation() const = 0;
        virtual int Humidity() const = 0;
        virtual int WindSpeedKMPH() const = 0;
    };

    // Original stub (kept, can be used in other tests)
    class SensorStub : public IWeatherSensor {
    public:
        int Humidity() const override { return 72; }
        int Precipitation() const override { return 70; }
        double TemperatureInC() const override { return 26; }
        int WindSpeedKMPH() const override { return 52; }
    };

    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }

    // New stub to expose bug
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
        string report = Report(sensor);
        cout << report << endl;
        assert(report.find("rain") != string::npos); // will fail
    }

    void TestHighPrecipitation()
    {
        SensorStub sensor;
        string report = Report(sensor);
        assert(report.length() > 0); // keeps old test
    }
}

void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}
