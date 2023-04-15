#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int n;
  extern char *aptarg;
  extern int optind;

  printf("Current Option : %d\n", optind);
  while ((n = getopt(argc, argv, "abc:")) != -1) {
    switch (n) {
      case 'a':
        printf("Option : a\n");
        break;
      
      case 'b':
        printf("Option : b\n");
        break;

      case 'c':
        printf("Option : c, Argument=%s\n", optarg);
        break;
    }
    printf("Next Option :%d\n", optind);
  }
}