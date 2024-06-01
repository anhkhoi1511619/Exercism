#include <math.h>
#include <stdint.h>

uint64_t square(uint8_t index) {
    if(index > 64) return 0;
    return pow(2, index -1);
}

uint64_t total()
{
    return UINT64_MAX;
}