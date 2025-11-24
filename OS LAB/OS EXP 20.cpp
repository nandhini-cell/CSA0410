#include <stdio.h>
#include <windows.h>

int data = 0, readersCount = 0;

HANDLE mutex;        // protects readersCount
HANDLE writeBlock;   // controls writer's access

DWORD WINAPI reader(LPVOID arg) {
    for (int i = 0; i < 10; i++) {

        WaitForSingleObject(mutex, INFINITE);
        readersCount++;

        if (readersCount == 1) {
            WaitForSingleObject(writeBlock, INFINITE);
        }

        ReleaseMutex(mutex);

        // Reading
        printf("Reader reads data: %d\n", data);
        Sleep(100);

        WaitForSingleObject(mutex, INFINITE);
        readersCount--;

        if (readersCount == 0) {
            ReleaseSemaphore(writeBlock, 1, NULL);
        }

        ReleaseMutex(mutex);
        Sleep(100);
    }
    return 0;
}

DWORD WINAPI writer(LPVOID arg) {
    for (int i = 0; i < 10; i++) {

        WaitForSingleObject(writeBlock, INFINITE);

        data++;
        printf("Writer writes data: %d\n", data);
        Sleep(100);

        ReleaseSemaphore(writeBlock, 1, NULL);
        Sleep(100);
    }
    return 0;
}

int main() {
    HANDLE rThread, wThread;

    mutex = CreateMutex(NULL, FALSE, NULL);
    writeBlock = CreateSemaphore(NULL, 1, 1, NULL);

    rThread = CreateThread(NULL, 0, reader, NULL, 0, NULL);
    wThread = CreateThread(NULL, 0, writer, NULL, 0, NULL);

    WaitForSingleObject(rThread, INFINITE);
    WaitForSingleObject(wThread, INFINITE);

    CloseHandle(mutex);
    CloseHandle(writeBlock);

    return 0;
}

