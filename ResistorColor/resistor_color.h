#ifndef HEADER_FILE
#define HEADER_FILE
typedef enum {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_color;

int color_code(resistor_band_color color);
#endif

