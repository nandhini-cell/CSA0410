#include <stdio.h>
#include <windows.h>

int counter = 0;

DWORD WINAPI threadFunction(LPVOID arg) {
    for (int i = 0; i < 5; i++) {
        counter++;
        printf("Thread running... counter = %d\n", counter);
        Sleep(200);
    }
    return 0;
}

int main() {
    HANDLE t1;

    t1 = CreateThread(NULL, 0, threadFunction, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    CloseHandle(t1);

    printf("Final counter = %d\n", counter);
    return 0;
}

