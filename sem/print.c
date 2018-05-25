#include "comm.h"

int main()
{
    int semid = Createsem(1);
    Initsem(semid,0,1);
    pid_t pid = fork();
    if(pid == 0) //child
    {
        //打印A
        while(1)
        {
            P(semid,0);
            printf("A");
            fflush(stdout);
            usleep(65432);
            printf("AA ");
            fflush(stdout);
            usleep(12345);
            V(semid,0);
        }
    }
    else if(pid > 0) //parent
    {
        //打印B
        while(1)
        {
            P(semid,0);
            printf("BB");
            fflush(stdout);
            usleep(12345);
            printf("B ");
            fflush(stdout);
            usleep(12345);
            V(semid,0);
        }
    }
    else
    {
        perror("fork");
        exit(1);
    }
    return 0;
}
