#include <stdio.h>
#include <pthread.h>

#include "kcol.h"

int counter = 0;
lock_t k;

void *
child (void *arg)
{
  char *t;
  int i;

  t = (char *) arg;
  for (i = 0; i < 1e5; i++)
    {
      lock (&k);
      counter = counter + 1;
      printf ("[%s] = %d\n", t, counter);
      unlock (&k);
    }
  return NULL;
}

int
main (int argc, char *arv[])
{
  pthread_t p1, p2;
  init (&k);

  pthread_create (&p1, NULL, child, "A");
  pthread_create (&p2, NULL, child, "B");
  pthread_join (p1, NULL);
  pthread_join (p2, NULL);
  return 0;
}
