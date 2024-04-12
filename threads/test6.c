#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/* handling the datarace problem using mutex lock and unlock */

pthread_mutex_t mutex;

void    *f(void *i)
{
    int x = 100000;
    while (x-- > 0)
    {
        pthread_mutex_lock(&mutex);
        (*(int *)i)++;
        pthread_mutex_unlock(&mutex);
    }
    return(NULL);
}

void ffff()
{
    system("leaks a.out");
}

int main()
{
    int i = 0;
    pthread_t th1;
    pthread_t th2;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&th1, NULL, f, &i);
    pthread_create(&th2, NULL, f, &i);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("--->%d", i);
    pthread_mutex_destroy(&mutex);
}