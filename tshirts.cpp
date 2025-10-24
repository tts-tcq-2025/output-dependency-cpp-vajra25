#include <string>
using namespace std;

string getTShirtSize(int shoulderWidth) {
    if (shoulderWidth <= 14)
        return "S";
    else if (shoulderWidth <= 16)
        return "M";
    else if (shoulderWidth <= 18)
        return "L";
    else
        return "XL";
}
