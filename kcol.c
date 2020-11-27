#include "kcol.h"

int
test_and_set (int *old_ptr, int new)
{
  int old = *old_ptr;
  *old_ptr = new;
  return old;
}

void
init (lock_t * lock)
{
  lock->flag = 0;
}

void
lock (lock_t * lock)
{
  while (test_and_set (&lock->flag, 1) == 1)
    ;
}

void
unlock (lock_t * lock)
{
  lock->flag = 0;
}
