#include <unistd.h>
#include <stdlib.h>

//write will output the num of characters that are writen into the file
//the first arg of write function is the fildes, default ones are below
//0 stdin
//1 stdout
//2 stderr

int main()
{
  int count;
  if ( write(1, "Here is some data\n", 18) != 18)
    write (2, "A write error has occurred on file descriptor\n", 46);
  // exit(0);
}
