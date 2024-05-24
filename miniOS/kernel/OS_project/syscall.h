#ifndef SYSCALL_H
#define SYSCALL_H

#include <sys/time.h>

//현우
void get_time();
int set_time(int hours, int miniutes, int seconds);

//지민
int createfile(const char *filename);
int writefile();
int deletefile(const char *filename);

//인아
int IPC_W();
int IPC_R();

//준영
int Fork();
int Exec();
int Abort();
int Exit(int status);
int wait_time(int seconds);
void wait_for_event();
void signal_event();

#endif
