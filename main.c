#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "kcol.h"

int counter = 0;

lock_t k;

void *
func1 (void *arg)
{
  int i;

  for (i = 0; i < 1e2; i++)
    {
      lock (&k);
      counter = counter + 1;
      unlock (&k);
    }
  return NULL;
}

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *
func2 (void *arg)
{
  int i;

  for (i = 0; i < 1e2; i++)
    {
      pthread_mutex_lock (&m);
      counter = counter + 1;
      pthread_mutex_unlock (&m);
    }
  return NULL;
}

void
perform_concurrent_execution (pthread_t * p1, pthread_t * p2,
			      void *(*f) (void *))
{
  pthread_create (p1, NULL, f, NULL);
  pthread_create (p2, NULL, f, NULL);
}

int
main (int argc, char *argv[])
{
  void *(*f) (void *);
  pthread_t p1, p2;
  char c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      {
	switch (c)
	  {
	  case 'n':
	    f = func1;
	    break;
	  case 'm':
	    f = func2;
	    break;
	  default:
	    fputs ("Usage: main -OPTION\n", stderr);
	    exit (0);
	  }
	perform_concurrent_execution (&p1, &p2, f);
	pthread_join (p1, NULL);
	pthread_join (p2, NULL);
	printf ("%d\n", counter);
      }
  return 0;
}
