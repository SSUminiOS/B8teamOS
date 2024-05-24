#ifndef EVENT_CONTROL_H
#define EVENT_CONTROL_H

#include <pthread.h>

extern pthread_cond_t cond;
extern pthread_mutex_t mutex;

void wait_for_event();
void signal_event();

#endif
