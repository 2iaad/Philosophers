#include <pthread.h>
#include <stdio.h>

// test show that threads dont share stack segment, they create their own!
// if they shared the same stack the result would be "200".

void    *f1(void *i)
{
    while (*(int *)i < 100)
        (*(int *)i)++;
    return(NULL);
}

void    *f2(void *i)
{
    while (*(int *)i < 100)
        (*(int *)i)++;
    return(NULL);
}

int main()
{
    pthread_t th1;
    pthread_t th2;
    int i = 0;

    pthread_create(&th1, NULL, f1, &i);
    printf("->%d\n", i); // ----> displays 0
    pthread_create(&th2, NULL, f2, &i);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("--->%d", i); // displays 100
}