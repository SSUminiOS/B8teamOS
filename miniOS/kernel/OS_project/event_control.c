#include "event_control.h"
#include <pthread.h>

// 조건 변수와 뮤텍스의 정의
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
