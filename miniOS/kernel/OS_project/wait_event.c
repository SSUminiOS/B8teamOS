
#include <stdio.h>

void wait_for_event() {
    pthread_mutex_lock(&mutex);  // 뮤텍스로 보호
    printf("Waiting for event...\n");
    pthread_cond_wait(&cond, &mutex);  // 조건 변수를 사용해 대기
    printf("Event signaled.\n");
    pthread_mutex_unlock(&mutex);  // 뮤텍스 잠금 해제
}
