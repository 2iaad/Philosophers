#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>

void *f()
{
    printf("Salam ana smiti ziad!\n");
    sleep(3);
    printf("thread->%d\n",getpid());
    return (NULL);
}

// piece of code shows that threads run in paralel and share the same pid

int main()
{
    pthread_t t1, t2;

    printf("process->%d\n",getpid());
    if (pthread_create(&t1, NULL, &f, NULL) != 0)
        printf("Error\n");
    pthread_create(&t2, NULL, &f, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}