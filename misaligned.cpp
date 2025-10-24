#include <string>
using namespace std;

string getColorForNumber(int number) {
    switch (number) {
        case 1: return "Brown";
        case 2: return "Red";
        case 3: return "Orange";
        case 4: return "Yellow";
        case 5: return "Green";
        default: return "Unknown";
    }
}

string formatMapping(int number, const string &color) {
    return to_string(number) + " | " + color;
}
