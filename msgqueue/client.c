#include "com.h"
#include <stdio.h>
#include <unistd.h>

int main()
{
    int msgid = OpenMsgQueue();
    char buf[1024] = {0};
    while(1)
    {
        printf("client > ");
        fflush(stdout);
        read(0,buf,sizeof(buf));
        SendMsgQueue(msgid,CLIENT_TYPE,buf);

        ReceiveMsgQueue(msgid,SERVER_TYPE,buf);
        printf("%s\n",buf);
    }
    return 0;
}
