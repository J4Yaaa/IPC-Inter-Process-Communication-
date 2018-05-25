#include "comm.h"

int Command(int size,int flag)
{
    key_t key = ftok(".",1);
    if(key < 0)
    {
        perror("ftok");
        exit(1);
    }
    int shmid = shmget(key,size,flag);
    if(shmid < 0)
    {
        perror("shmget");
        exit(1);
    }
    return shmid;
}

int CreateShm(int size)
{
    return Command(size,IPC_CREAT | IPC_EXCL | 0666);
}

int OpenShm()
{
    return Command(0,IPC_CREAT);
}

int DestoryShm(int shmid)
{
    if(shmctl(shmid,IPC_RMID,0) < 0)
    {
        perror("shmctl");
        exit(1);
    }
    return 0;
}
