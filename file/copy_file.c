#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/*
// 27.62 system...

int main() 
{
 char c;
 int in, out;
 in = open("file.in", O_RDONLY);
 out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
 while(read(in,&c,1) == 1)
   write(out, &c, 1);

 printf("\ndone\n");
 exit(0);
}
*/

/**
//0.03 system = =
int main() 
{
 char block[1024];
 int in, out;
 int nread;
 in = open("file.in", O_RDONLY);
 out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
 while((nread=read(in,block,sizeof(block))) > 0)
   write(out, block, nread);

 printf("\ndone\n");
 exit(0);
}
**/

//0.00system --...
int main() 
{
  int c;
  FILE* in, *out;
  in = fopen("file.in", "r");
  out = fopen("file.out", "w");
  while((c = fgetc(in)) != EOF)
    fputc(c, out);

  printf("\ndone\n");
  exit(0);
}
