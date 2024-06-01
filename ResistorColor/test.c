#include "resistor_color.c"
#include <stdio.h>
int main(void)
{
   int result = color_code(YELLOW);
   printf("Hello, World!+ %d",(result));

   unsigned int value = 20;
   unsigned int *pointer;

   pointer = &value;
   printf("Address of var variable: %x\n", &value);
   printf("Address of pointer variable: %x\n", pointer);
   printf("Value of pointer: %x\n", *pointer);
   printf("Value of value: %x\n", value);

   return 0;
}