#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

//create default mod 310
//maybe it is relative to umask
int main()
{
  int fildes = open("temp.file", O_WRONLY|O_APPEND|O_CREAT);
  int count = 0x100000;
  while(count > 0)
  {
    write (fildes, "hello world\n", 12);
    count --;
  }

  close(fildes);
}
