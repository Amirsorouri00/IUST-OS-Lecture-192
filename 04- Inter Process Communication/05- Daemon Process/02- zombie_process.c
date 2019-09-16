#include<stdio.h>
#include<stdlib.h>

int main() {
   int pid;
   pid = fork();
   if (pid == 0) {
      system("ps -f");
      printf("Child: pid is %d and ppid is %d\n",getpid(),getppid());
      exit(0);
   } else {
      printf("Parent: pid is %d and ppid is %d\n",getpid(),getppid());
      sleep(10);
      system("ps aux|grep Z");
   }
   return 0;
}