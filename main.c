// Test-and-set approach
#include <stdio.h>
#include <pthread.h>

#include "kcol.h"

lock_t k;
static volatile int counter = 0;

void *child(void *args) {
    int i;
    for (i = 0; i < 1e1; i++) {
        lock(&k); 
        counter = counter + 1;
        unlock(&k); 
    }
    return NULL;
}

int
main(int argc, char *arv[]) {
    init(&k);
    pthread_t p1, p2;

    pthread_create(&p1, NULL, child, NULL);
    pthread_create(&p2, NULL, child, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("counter = %d\n", counter);
    return 0;
}
