#pragma once
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

//这里的nsems表示创建的信号量集中有多少个信号(信号量的个数)
int Createsem(int nsems);

void Destorysem(int semid);

//nums 表示信号集中信号量的序号,从 0 开始
//value 表示初始化时,信号量中资源的个数
//      system V信号量中,value不会小于0
void Initsem(int semid,int nums,int value);

//nums 表示对信号量集中的哪一个信号进行P操作
//这里我们实现的是信号量集中只有一个信号
void P(int semid,int nums);

void V(int semid,int nums);
