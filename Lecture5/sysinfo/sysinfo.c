#include <sys/sysinfo.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  struct sysinfo sysin;

  if (sysinfo(sysin) == -1)
  {
    perror("sysinfo");
    exit(1);
  }
  printf("uptime: %ld\n", sysin.uptime);
  printf("load: %lu\n", sysin.load);
  printf("Total ram: %lu\n", sysin.totalram);
  printf("free ram: %lu\n", sysin.freeram);
  printf("shared ram: %lu\n", sysin.sharedram);
  printf("total swap: %lu\n", sysin.totalswap);
  printf("free swap: %lu\n", sysin.freeswap);
  printf("process: %lu\n", sysin.procs);

  return (0);
}
