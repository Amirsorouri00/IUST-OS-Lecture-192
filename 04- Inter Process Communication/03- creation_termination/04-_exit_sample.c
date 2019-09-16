#include <stdio.h>
#include <unistd.h>

void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

int main() {
   atexit(exitfunc);
   printf("Hello, World!\n");
   _exit (0);
}