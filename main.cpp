#include <iostream>
using namespace std;

// Declare all test functions
void testTShirtSize();
void testMisaligned();
void testWeatherReport();

int main() {
    testTShirtSize();
    testMisaligned();
    testWeatherReport();

    cout << "✅ All tests passed successfully!" << endl;
    return 0;
}
