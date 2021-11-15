#include "defs.h"

void trem_hndl(int );

int main(void)
{
    struct msgbuf temp_msg;
    ssize_t nbytes; 
    key_t upsrvk, dwnsrvk;
    
    signal(SIGINT, trem_hndl);

    printf("Configure local server keys...\n");
    upsrvk = Ftok(SERVER_KEY_PATH_NAME, UP);
    dwnsrvk = Ftok(SERVER_KEY_PATH_NAME, DOWN);
    printf("Server keys configured succesfully\n");
    
    printf("Initialize UP and Down Queues...\n");
    msgqupid = Msgget(upsrvk, SERVER_FLAGS);
    msgqdwnid = Msgget(dwnsrvk, SERVER_FLAGS);
    printf("Queues Initialized\nReady to send/recieve messages\n");

    for(;;)
    {
        printf("\nWaiting for a message...\n");
        if((nbytes = msgrcv( msgqupid, &temp_msg, sizeof(temp_msg.mdata), 0, !IPC_NOWAIT)) == -1)
        {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("%d bytes recieved from %d\n", nbytes, temp_msg.mtype);
        printf("Data recieved: %s\n", temp_msg.mdata);

        printf("Processing data....\n");
        toggle_message(temp_msg.mdata);

        printf("Data processed successfully...\n"
                "Preparing to send the processed data\n");
        if(msgsnd( msgqdwnid, &temp_msg, sizeof(temp_msg.mdata), !IPC_NOWAIT) == -1)
        {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("Message send succesfully to %d\n", temp_msg.mtype);
    }

    return 0;
}

void trem_hndl(int signum)
{
    if(msgctl( msgqupid, IPC_RMID, 0) == -1)
        perror("msgctl");
    if(msgctl( msgqdwnid, IPC_RMID, 0) == -1)
        perror("msgctl");

    exit(0);
}
    
