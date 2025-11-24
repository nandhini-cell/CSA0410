#include <stdio.h>
#include <windows.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE] = {0};
int produced = 0, consumed = 0;

HANDLE emptySem, fullSem;
HANDLE mutex;

DWORD WINAPI producer(LPVOID arg) {
    while (produced < MAX_ITEMS) {

        WaitForSingleObject(emptySem, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] == 0) {
                buffer[i] = produced + 1;
                printf("Produced: %d\n", buffer[i]);
                produced++;
                break;
            }
        }

        ReleaseMutex(mutex);
        ReleaseSemaphore(fullSem, 1, NULL);
        Sleep(200);
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID arg) {
    while (consumed < MAX_ITEMS) {

        WaitForSingleObject(fullSem, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] != 0) {
                printf("Consumed: %d\n", buffer[i]);
                buffer[i] = 0;
                consumed++;
                break;
            }
        }

        ReleaseMutex(mutex);
        ReleaseSemaphore(emptySem, 1, NULL);
        Sleep(300);
    }
    return 0;
}

int main() {
    HANDLE prodThread, consThread;

    emptySem = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    fullSem  = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);

    prodThread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    consThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(prodThread, INFINITE);
    WaitForSingleObject(consThread, INFINITE);

    CloseHandle(emptySem);
    CloseHandle(fullSem);
    CloseHandle(mutex);
    CloseHandle(prodThread);
    CloseHandle(consThread);

    return 0;
}

