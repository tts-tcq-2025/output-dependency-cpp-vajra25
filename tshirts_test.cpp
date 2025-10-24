#include <cassert>
#include "tshirts.cpp"

void testTShirtSize() {
    assert(getTShirtSize(13) == "S");
    assert(getTShirtSize(15) == "M");
    assert(getTShirtSize(17) == "L");
    assert(getTShirtSize(19) == "XL");
}
