#include <pthread.h>
#include <stdio.h>

/* case where we experience data race condition; D.R occurs after increment a variable
above 1 million times, because while incrementing, the second thread will execute the 
function and do the same thing, if we only increment 100 times the loop will finish
before the creation of the second time */

void    *f(void *i)
{
    int x = 100000;
    while (x-- > 0)
        (*(int *)i)++;
    return(NULL);
}


int main()
{
    int i = 0;
    pthread_t th1;
    pthread_t th2;

    pthread_create(&th1, NULL, f, &i);
    pthread_create(&th2, NULL, f, &i);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("--->%d", i);
}