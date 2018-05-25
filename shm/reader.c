#include "comm.h"
#include <unistd.h>

int main()
{
    int shmid = OpenShm();
    char* addr = (char*)shmat(shmid,NULL,0);
    while(1)
    {
        printf("%s\n",addr);
        sleep(1);
    }
    shmdt(addr);
    return 0;
}
