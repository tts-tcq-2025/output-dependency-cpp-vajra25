#include <iostream>
#include <assert.h>
#include <string>

// Production code (unchanged logic)
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

// New helper function to separate logic
std::string getColorLine(int i, int j) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    return std::to_string(i * 5 + j) + " | " + majorColor[i] + " | " + minorColor[j];
}

// Stronger test
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 25);

    // New unit tests for each line
    assert(getColorLine(0,0) == "0 | White | Blue");
    assert(getColorLine(0,1) == "1 | White | Orange"); // will fail
    assert(getColorLine(1,0) == "5 | Red | Blue");     // will fail

    std::cout << "All is well (maybe!)\n";
}
