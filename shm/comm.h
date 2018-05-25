#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//size 表示创建的共享内存的大小,以页为单位,且会向上取整到4096的整数倍
//     若给定 1024,系统会分配一页(4096)
//     若给定 4097,系统会分配两页(8192)
int CreateShm(int size);

int OpenShm();

int DestoryShm(int shmid);
