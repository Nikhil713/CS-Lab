#include<stdio.h>
#include<unistd.h>

int main() {

   int check,pipes[2];
   char readmessage[10],writemessages[2][10]={"A", "B"};

   check = pipe(pipes);
   
   if (check == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   
   write(pipes[1], writemessages[0], sizeof(writemessages[0]));
   printf("\nWriting to pipe : First Message => %s\n", writemessages[0]);

   read(pipes[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe : First Message => %s\n", readmessage);
   
   write(pipes[1], writemessages[1], sizeof(writemessages[0]));
   printf("\nWriting to pipe : Second Message => %s\n", writemessages[0]);
   
   read(pipes[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe : Second Message => %s\n", readmessage);
   
   return 0;
}