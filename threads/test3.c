#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_arg
{
    int *arr;
    int n;
}   t_arg;

void    *f(void *arg)
{
    int i = 0;
    // (t_arg *)arg;
    while (i <= ((t_arg *)arg)->n)
    {
        ((t_arg *)arg)->arr[i] = i;
        i++;
    }
    return (NULL);
}

// passing a struct to to the thread to modify its content hehe

int main(void)
{
    int        arr[100];
    t_arg      arg;
    pthread_t  th1;


    arg.arr = &arr[0];
    arg.n  = 90;
    pthread_create(&th1, NULL, f, &arg);
    pthread_join(th1, NULL);

    int i = 0;
    while (i <= arg.n)
    {
        printf("%d-",arg.arr[i]); // printing the result of the thread
        i++;
    }
}
