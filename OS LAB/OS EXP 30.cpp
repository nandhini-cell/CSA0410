#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI myThreadFunction(LPVOID lpParam)
{
    printf("Inside the thread\n");
    return 0;   // end of thread
}

void fun()
{
    HANDLE threadHandle;
    DWORD threadId;

    threadHandle = CreateThread(
        NULL,       // default security attributes
        0,          // default stack size
        myThreadFunction, // thread function name
        NULL,       // argument to thread function
        0,          // default creation flags
        &threadId); // returns the thread identifier

    if (threadHandle == NULL) {
        printf("Error in creating thread\n");
        return;
    }

    printf("This line may be printed before thread terminates\n");

    // Wait for the thread to finish
    WaitForSingleObject(threadHandle, INFINITE);

    printf("This line will be printed after thread ends\n");

    CloseHandle(threadHandle);
}

int main()
{
    fun();
    return 0;
}

