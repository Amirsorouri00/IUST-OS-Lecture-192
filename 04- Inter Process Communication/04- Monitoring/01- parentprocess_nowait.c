#include<stdio.h>

int main() {
   int pid;
   pid = fork();
   
   // Child process
   if (pid == 0) {
      system("ps -ef");
      sleep(10);
      system("ps -ef");
   } else {
      sleep(3);
   }
   return 0;
}