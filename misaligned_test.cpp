#include <cassert>
#include "misaligned.cpp"

void testMisaligned() {
    assert(formatMapping(1, "Brown") == "1 | Brown");
    assert(formatMapping(2, "Red") == "2 | Red");
    assert(formatMapping(3, "Orange") == "3 | Orange");
    assert(formatMapping(4, "Yellow") == "4 | Yellow");
    assert(formatMapping(5, "Green") == "5 | Green");
}
