#include "tshirts.h"

std::string tshirtSize(int shoulderWidth) {
    if (shoulderWidth < 36)
        return "S";
    else if (shoulderWidth > 36 && shoulderWidth < 40)
        return "M";  // ❌ BUG: boundary 36 or 40 missing
    else
        return "L";
}
