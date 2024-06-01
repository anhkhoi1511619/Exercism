#include "grains.c"
#include <stdio.h>
int main() {
   uint64_t excepted_result = 1ull;
   uint64_t actual_result = square(1);
   printf("Test1 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   excepted_result = 2ull;
   actual_result = square(2);
   printf("Test2 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

    printf("\n");

   excepted_result = 0;
   actual_result = square(0);
   printf("Test3 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

    printf("\n");

   excepted_result = 0;
   actual_result = square(65);
   printf("Test4 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   uint64_t excepted_special_result = 18446744073709551615ull;
   uint64_t actual_special_result = total();
   printf("Test5 run with result+ %s",(excepted_special_result == actual_special_result ? "TRUE" : "FALSE"));

   printf("\n");
   return 0;
}