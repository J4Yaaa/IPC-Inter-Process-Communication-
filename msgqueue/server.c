#include "com.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    int msgid = CreateMsgQueue();
    char buf[1024] = {0};
    while(1)
    {
        ReceiveMsgQueue(msgid,CLIENT_TYPE,buf);
        printf("%s\n",buf);

        printf("server >");
        fflush(stdout);
        read(0,buf,sizeof(buf));
        SendMsgQueue(msgid,SERVER_TYPE,buf);
    }
    DestoryMsgQueue();
    return 0;
}
