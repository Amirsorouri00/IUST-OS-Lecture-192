/* Prints numbers from 1 to 10 using while loop */
#include<stdio.h>

void main() {
   int value = 1;
   while (value <= 10) {
      printf("%d\t", value);
      value++;
   }
   printf("\n");
   return;
}