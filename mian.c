#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    struct timeval aa;
    struct timeval bb;
    gettimeofday(&aa, NULL);
    printf("%d", usleep(1000 * 1000));
}
// int main()
// {
//     struct timeval aa;
//     struct timeval bb;
//     gettimeofday(&aa, NULL);
//     printf("%d\n",aa.tv_usec);
//     usleep(200 * 1000);
//     gettimeofday(&bb, NULL);
//     printf("%d\n",bb.tv_usec);

//     printf("\n---->%d--\n ",(bb.tv_usec - aa.tv_usec) / 1000);
// }