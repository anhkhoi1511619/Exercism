#include "resistor_color.c"
#include <stdio.h>
int main(void)
{
   int result = color_code(YELLOW);
   float a = 10.0;
   int b = 0x0b1000000;
   int b = 127;


   printf("Hello, World!+ %x",b);

   unsigned int value = 20;
   unsigned int *pointer;

   pointer = &value;
   printf("Address of var variable: %x\n", &value);
   printf("Address of pointer variable: %x\n", pointer);
   printf("Value of pointer: %x\n", *pointer);
   printf("Value of value: %x\n", value);

   return 0;
}