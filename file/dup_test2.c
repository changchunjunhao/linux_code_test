#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>

void jobs(int in1, int in2) 
{
  write(in1, "1234567890", 10);
  write(in2, "hellow" , 6);
  
  printf ("\n");
}



int main()
{
  char filepath[] = "file.test2";
  int in1, in2;
  in1 = open(filepath, O_WRONLY|O_CREAT);
  //in2 = open(filepath, O_WRONLY|O_CREAT);
  in2 = dup(in1);
  jobs(in1,in2);

  close(in1);
  close(in2);
  char buffer[20];
  int in3 = open(filepath, O_RDONLY);
  int nread = read(in3, buffer, 10);
  write(in3, buffer, nread);
  close(in3);
  printf("done");
  exit(0);
}

