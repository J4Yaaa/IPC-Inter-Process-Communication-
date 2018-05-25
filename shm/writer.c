#include "comm.h"
#include <unistd.h>

int main()
{
    int shmid = CreateShm(1024);
    char* addr = (char*)shmat(shmid,NULL,0);
    int i = 0;
    while(1)
    {
        addr[i++] = 'A';
        addr[i] = '\0';
        sleep(1);
    }
    shmdt(addr);
    DestoryShm(shmid);
    return 0;
}
