#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// int x = 0;

void    *f1(void *x)
{
    *(int *)x = 42; // casting to int* then dereferencing it hehe
    printf("thread->%d\n",*(int *)x);
    return(NULL);
}

// passing a variable(located in the stack) to the thread and modifying it

int main()
{
    int x = 1337;
    pthread_t t1;

    pthread_create(&t1, NULL, &f1, &x);
    pthread_join(t1, NULL);
    printf("process->%d\n",x);
}