#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int fd;

  fd = open("test.txt", O_CREAT | O_EXCL, 0644);
  if (fd == -1) {
    perror("EXCL");
    exit(1);
  }
  close(fd);
  return (0);
}
