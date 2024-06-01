#include "difference_of_squares.c"
#include <stdio.h>
int main() {
   int excepted_result = 225;
   int actual_result = square_of_sum(5);
   printf("Test1 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   excepted_result = 25502500;
   actual_result = square_of_sum(100);
   printf("Test2 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   excepted_result = 55;
   actual_result = sum_of_squares(5);
   printf("Test3 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   excepted_result = 338350;
   actual_result = sum_of_squares(100);
   printf("Test4 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));

   printf("\n");

   excepted_result = 25164150;
   actual_result = difference_of_squares(100);
   printf("Test5 run with result+ %s",(excepted_result == actual_result ? "TRUE" : "FALSE"));
   return 0;
}