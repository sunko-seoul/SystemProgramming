#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signo)
{
  if (signo == SIGINT)
    printf("Caught SIGINT!\n");
  else if (signo  == SIGTERM)
    printf("Caught SIGTERM!\n");
  else {
    fprintf(stderr, "Unexpected signal!\n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}


int main(void)
{
  /*
   * signal_handler를 SIGINT용 시그널 핸들러로 등록
   */
  if (signal(SIGINT, signal_handler) == SIG_ERR) {
    fprintf(stderr, "Cannot handle SIGINT!\n");
    exit(EXIT_FAILURE);
  }

  /*
   * signal_handler를 SIGTERM용 시그널 핸들러로 등록
   */
  if(signal(SIGTERM, signal_handler) == SIG_ERR){
    fprintf(stderr, "Cannot handle SIGTERM");
    exit(EXIT_FAILURE);
  }

  if (signal(SIGPROF, SIG_DFL) == SIG_ERR){
    fprintf(stderr, "Cannot reset SIGROF!\n");
    exit(EXIT_FAILURE);
  }

  if (signal(SIGHUP, SIG_IGN) == SIG_ERR){
    fprintf(stderr, "Cannot ignore SIGHUP");
    exit(EXIT_FAILURE);
  }

  for (;;)
    pause();

  return (0);
}
