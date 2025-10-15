#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";

    // Original tests
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // New tests to expose bug
    assert(size(38) == 'M'); // edge case missing in original test
    assert(size(42) == 'M'); // edge case missing in original test

    std::cout << "All is well (maybe!)\n";
}


