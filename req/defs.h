#ifndef DEFS_H
#define DEFS_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* ftok parameters */
#define SERVER_KEY_PATH_NAME "./server-key"
#define UP 'U'
#define DOWN 'D'

/* msg queue parameters */
#define SERVER_FLAGS IPC_CREAT | IPC_EXCL | 0666
#define CLIENT_FLAGS 0666
static int msgqupid, msgqdwnid;

#define MAX_DATA_SIZE 256
struct msgbuf
{
    long mtype;
    char mdata[MAX_DATA_SIZE];
};

void toggle_message(char*);
void read_line(char*, int);

/* Wrapper functions */
key_t Ftok(const char*, int);
int Msgget(key_t, int);

#endif
