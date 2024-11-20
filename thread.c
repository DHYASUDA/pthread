#include <stdio.h>
#include <pthread.h>

void* print_hello(void* data) {
    int thread_number = (int)(long)data; // Convert `void*` back to `int`
    printf("Hello from thread %d\n", thread_number);
    return NULL;
}

int main() {
    pthread_t thread_id[5];
    for (int k = 0; k < 5; k++) {
        if (pthread_create(&thread_id[k], NULL, print_hello, (void*)(long)k) != 0) {
            fprintf(stderr, "Error creating thread %d\n", k);
        }
    }

    // Wait for all threads to finish
    for (int k = 0; k < 5; k++) {
        pthread_join(thread_id[k], NULL);
    }

    return 0;
}
