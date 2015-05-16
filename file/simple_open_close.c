#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
  int fildes = open("temp.file", O_WRONLY|O_APPEND);
  
  if (fildes == -1)
  {
    write(2, "An error occurs when open temp.file\n", 100);
  }

  else if (write(fildes, "1234567890\n", 11) != 11)
  {
    write(2, "error when write into it\n", 100);
  }
  
  //printf("fildes is %d\n", fildes);
  close(fildes);

  write (1, "done", 4);
 
  return 0;
    
}
