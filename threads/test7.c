#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

// int main()
// {
//     while (usleep(35654654))
//         ;
// }
int main()
{
    struct timeval aaaa;
    gettimeofday(&aaaa, NULL);
    printf("%d\n",aaaa.tv_usec);
    sleep(1);
    gettimeofday(&aaaa, NULL);
    printf("%d\n",aaaa.tv_usec);
}