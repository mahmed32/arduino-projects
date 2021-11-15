#include "defs.h"

int main(void)
{
    int locaddr;
    ssize_t nbytes;
    struct msgbuf msg;
    key_t upsrvk, dwnsrvk;

    printf("Configuring local address...\n");
    locaddr = getpid() % 10000; /* need only the first four digits */
    msg.mtype = locaddr;
    printf("local address: %d\n", locaddr);

    printf("Get remote server keys...\n");
    upsrvk = Ftok(SERVER_KEY_PATH_NAME, UP);
    dwnsrvk = Ftok(SERVER_KEY_PATH_NAME, DOWN);

    printf("Connecting to remote server...\n");
    msgqupid = Msgget(upsrvk, CLIENT_FLAGS);
    msgqdwnid = Msgget(dwnsrvk, CLIENT_FLAGS);
    printf("Connection Success\n");

    for(;;)
    {
        printf("\nplease input a message:\n");
        read_line(msg.mdata, sizeof(msg.mdata));

        printf("message read, prepare to upload....\n");
        if(msgsnd( msgqupid, &msg, sizeof(msg.mdata), !IPC_NOWAIT) == -1)
        {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("upload success\n");

        printf("waiting for a response.....\n");
        if((nbytes = msgrcv( msgqdwnid, &msg, sizeof(msg.mdata), msg.mtype, !IPC_NOWAIT) == -1))
        {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("Response: %s\n", msg.mdata);

    }

    return 0;
}
