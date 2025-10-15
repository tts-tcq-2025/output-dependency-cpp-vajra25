#include <iostream>
#include <cassert>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName; // still returns '\0' for 38 or 42 → test will fail
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";

    // Original tests
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // New tests to expose bug
    assert(size(38) == 'M'); // will fail
    assert(size(42) == 'M'); // will fail

    std::cout << "All is well (maybe!)\n";
}
