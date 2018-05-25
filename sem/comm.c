#include "comm.h"

int Comm(int flags,int nsems)
{
    key_t key = ftok(".",1);
    if(key < 0)
    {
        perror("ftok");
        exit(1);
    }
    int semid = semget(key,nsems,flags);
    if(semid < 0)
    {
        perror("semget");
        exit(1);
    }
    return semid;
}

int Createsem(int nsems)
{
    return Comm(IPC_CREAT | IPC_EXCL | 0666,nsems);
}

void Destorysem(int semid)
{
    if(semctl(semid,IPC_RMID,0) < 0)
    {
        perror("semctl");
        exit(1);
    }
}

void Initsem(int semid,int nums,int value)
{
    union semun sem;
    sem.val = value;
    if(semctl(semid,nums,SETVAL,sem) < 0)
    {
        perror("semctl SETVAL");
        exit(1);
    }
    return;
}

void CommPV(int semid,int nums,int value)
{
    struct sembuf buf;
    buf.sem_num = nums;
    buf.sem_op = value;
    buf.sem_flg = 0;
    if(semop(semid,&buf,1) < 0)
    {
        perror("semop");
        exit(1);
    }
}

void P(int semid,int nums)
{
    CommPV(semid,nums,-1);
}

void V(int semid,int nums)
{
    CommPV(semid,nums,1);
}
