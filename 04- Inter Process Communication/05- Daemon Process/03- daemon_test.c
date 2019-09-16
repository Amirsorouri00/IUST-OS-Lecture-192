#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
   pid_t pid;
   int counter;
   int fd;
   int max_iterations;
   char buffer[100];
   if (argc < 2)
   max_iterations = 5;
   else {
      max_iterations = atoi(argv[1]);
      if ( (max_iterations <= 0) || (max_iterations > 20) )
      max_iterations = 10;
   }
   pid = fork();
   
   // Unable to create child process
   if (pid < 0) {
      perror("fork error\n");
      exit(1);
   }
   
   // Child process
   if (pid == 0) {
      fd = open("/tmp/DAEMON.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
      if (fd == -1) {
         perror("daemon txt file open error\n");
         return 1;
      }
      printf("Child: pid is %d and ppid is %d\n", getpid(), getppid());
      printf("\nChild process before becoming session leader\n");
      sprintf(buffer, "ps -ef|grep %s", argv[0]);
      system(buffer);
      setsid();
      printf("\nChild process after becoming session leader\n");
      sprintf(buffer, "ps -ef|grep %s", argv[0]);
      system(buffer);
      close(STDIN_FILENO);
      close(STDOUT_FILENO);
      close(STDERR_FILENO);
   } else {
      printf("Parent: pid is %d and ppid is %d\n", getpid(), getppid());
      printf("Parent: Exiting\n");
      exit(0);
   }
   
   // Executing max_iteration times
   for (counter = 0; counter < max_iterations; counter++) {
      sprintf(buffer, "Daemon process: pid is %d and ppid is %d\n", getpid(), getppid());
      write(fd, buffer, strlen(buffer));
      sleep(2);
   }
   strcpy(buffer, "Done\n");
   write(fd, buffer, strlen(buffer));
   
   // Can't print this as file descriptors are already closed
   printf("DoneDone\n");
   close(fd);
   return 0;
}