#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
  struct stat a;
  stat("file.test", &a);
  printf("st_ino is %d\n", a.st_ino);
  return 0;
}
