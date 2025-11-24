#include <stdio.h>
#include <pthread.h>

void* func(void *arg) {
    printf("%s\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    char msg1[] = "Hello from Thread 1!";
    char msg2[] = "Hello from Thread 2!";

    pthread_create(&t1, NULL, func, (void*)msg1);
    pthread_create(&t2, NULL, func, (void*)msg2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

