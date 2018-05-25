#include "com.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>


int Commend(int flags)
{
    key_t key = ftok(".",1);
    if(key < 0)
    {
        perror("ftok");
        exit(1);
    }
    int msgid = msgget(key,flags);
    if(msgid < 0)
    {
        perror("magget");
        exit(1);
    }
    return msgid;
}

int CreateMsgQueue()
{
    return Commend(IPC_CREAT | IPC_EXCL | 0666);
}

int OpenMsgQueue()
{
    return Commend(IPC_EXCL);
}

void DestoryMsgQueue()
{
    int msgid = OpenMsgQueue();
    if((msgctl(msgid,IPC_RMID,NULL)) < 0)
    {
        perror("msgctl");
        exit(1);
    }
}


void SendMsgQueue(int msgid,int type,char* msg)
{
    msgbuf buf;
    buf.mtype = type;
    strcpy(buf.mtest,msg);

    if(msgsnd(msgid,&buf,sizeof(buf.mtest),0) < 0)
    {
        perror("msgsnd");
        exit(1);
    }
}

void ReceiveMsgQueue(int msgid,int type,char out[])
{
    msgbuf buf;
    if(msgrcv(msgid,&buf,sizeof(buf.mtest),type,0) < 0)
    {
        perror("msgrcv");
        exit(1);
    }
    strcpy(out,buf.mtest);
}


/////////////////////////////////////////////////////////////
//测试代码
/////////////////////////////////////////////////////////////
#if 0
void testcreat()
{
    int ret = CreateMsgQueue();
    printf("msgid = %d\n",ret);
}

void testopen()
{
    int ret = OpenMsgQueue();
    printf("msgid = %d\n",ret);

}

void testdestory()
{
    DestoryMsgQueue();
}

int main()
{
    /* testcreat(); */
    /* testopen(); */
    testdestory();
    return 0;
}

#endif
