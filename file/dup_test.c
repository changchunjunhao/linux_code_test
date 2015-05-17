#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>

void jobs(int in1, int in2) 
{
  printf("in1 is %d, in2 is %d", in1, in2);
  if (-1 == in1)
  {
    write (2, "error occur when open in1\n", 100);
    exit(0);
  }
  if (-1 == in2)
  {
    write (2, "error occur when open in2\n", 100);
    exit(0);
  }
  lseek(in1, 10, SEEK_SET);
  char buffer[20];
  int nread;
  printf("\nin1:\n");
  if ((nread = read(in1, buffer, 10)) > 0 ) 
  {
    write(1, buffer, 10);
  }
  printf("\nin2:\n");
  if ((nread = read(in2, buffer, 20)) > 0 ) 
  {
    write(1, buffer, 20);
  }
  printf ("\n");
}
/**
in1 is 3, in2 is 4

in1:
unistd.h>

in2:
#include <unistd.h>
**/

int main()
{
  int in1, in2;
  in1 = open("file.test", O_RDONLY);
  in2 = open("file.test", O_RDONLY);
  
  jobs(in1,in2);

  close(in1);
  close(in2);
  exit(0);
}




/***
in1 is 3, in2 is 4
in1:
unistd.h>

in2:
#include <sys/stat.h
 ***/

/**
int main()
{
  int in1, in2;
  in1 = open("file.test", O_RDONLY);
  in2 = dup(in1);
  
  jobs(in1, in2);

  close(in1);
  close(in2);
  exit(0);
}
**/
