#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for using read(..) */

#define max_int 255
#define byte char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;

  /* the following is the prototype for the read system call */
  /* int read(int fildes, void *buf, size_t nbyte);  */

  unsigned char input[10];
  int i;

  /* read the 10 bytes */

  read(STDIN_FILENO, input, count);
  for (i = 0; i < count; i++) {
    if (i == 5) 
      checksum = input[i];  
    else {
      sum += input[i];  
      if (sum > max_int) { 
        sum = (sum & 0xFF) + 1; 
      }
    }
  }
  complement = ~sum; /* take one's complement */

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}

