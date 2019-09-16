#include<stdio.h>
#include<unistd.h>

void main() {
   execl("./helloworld", "./helloworld", (char *)0);
   printf("This wouldn't print\n");
   return;
}