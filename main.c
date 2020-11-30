#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "kcol.h"
#include "anki.h"

#define LIMIT 1e3

int counter = 0;
lock_t k;

void *
func1 (void *arg)
{
  int i;

  for (i = 0; i < LIMIT; i++)
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

  for (i = 0; i < LIMIT; i++)
    {
      pthread_mutex_lock (&m);
      counter = counter + 1;
      pthread_mutex_unlock (&m);
    }
  return NULL;
}

int
main (int argc, char *argv[])
{
  pthread_t p1, p2;
  void *(*f) (void *);
  char c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      {
	switch (c)
	  {
	  case 'n':
	    init (&k);
	    f = func2;
	    break;
	  case 'm':
	    f = func1;
	    break;
	  default:
	    fputs ("Usage: main -OPTION\n", stderr);
	    exit (0);
	  }
	pthread_create (p1, NULL, f, NULL);
	pthread_create (p2, NULL, f, NULL);
	pthread_join (p1, NULL);
	pthread_join (p1, NULL);
	printf ("%d\n", counter);
      }
  return 0;
}
