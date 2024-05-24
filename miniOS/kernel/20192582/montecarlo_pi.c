#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
int num_points_in_circle = 0;
int total_points = 100000;
pthread_mutex_t lock; 

void* gen_rand_points(void* arg){
    int points_per_thread = *((int*)arg);
    int count = 0;
    
    unsigned int seed = time(NULL);
    for (int i = 0; i < points_per_thread; i++){
        double x = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
        if (x * x + y * y <= 1.0){
            count++;
        }
    }
    
    pthread_mutex_lock(&lock);
    num_points_in_circle += count;
    pthread_mutex_unlock(&lock);
    
    pthread_exit(NULL);
}

double montecarlo_pi(int num_threads){
    pthread_t threads[num_threads];
    int points_per_thread = total_points / num_threads;
    int thread_args[num_threads];

    // 초기화
    num_points_in_circle = 0;
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < num_threads; i++){
        thread_args[i] = points_per_thread;
        pthread_create(&threads[i], NULL, gen_rand_points, (void*)&thread_args[i]);
    }
    
    for (int i = 0; i < num_threads; i++){
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    
    double pi = ((double)num_points_in_circle / total_points) * 4.0;
    return pi;
}

