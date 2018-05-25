#pragma once
#include <sys/types.h>
#include <sys/ipc.h>

#define CLIENT_TYPE 1
#define SERVER_TYPE 2

typedef struct msgbuf
{
    long mtype;
    char mtest[128];
}msgbuf;


int CreateMsgQueue();

int OpenMsgQueue();

void DestoryMsgQueue();

void SendMsgQueue(int msgid,int type,char* msg);

void ReceiveMsgQueue(int msgid,int type,char out[]);
