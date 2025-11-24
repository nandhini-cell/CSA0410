#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

// Initialize memory to -1
void initializeMemory() {
    for (int i = 0; i < MAX_MEMORY; i++) {
        memory[i] = -1;
    }
}

// Display free blocks
void displayMemory() {
    int i = 0;
    int found = 0;

    printf("\nMemory Status:\n");

    while (i < MAX_MEMORY) {
        if (memory[i] == -1) {
            found = 1;
            int start = i;

            while (i < MAX_MEMORY && memory[i] == -1) {
                i++;
            }

            printf("Free memory block: %d - %d\n", start, i - 1);
        } else {
            i++;
        }
    }

    if (!found) {
        printf("No free memory available.\n");
    }
}

// FIRST-FIT Allocation
void allocateMemory(int processId, int size) {
    int start = -1;
    int blockSize = 0;

    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == -1) {
            if (blockSize == 0)
                start = i;

            blockSize++;
        } else {
            blockSize = 0;
        }

        if (blockSize >= size)
            break;
    }

    if (blockSize >= size) {
        for (int i = start; i < start + size; i++)
            memory[i] = processId;

        printf("\nAllocated block %d - %d to Process %d\n",
               start, start + size - 1, processId);
    } else {
        printf("\nAllocation FAILED for Process %d (not enough space)\n", processId);
    }
}

// Deallocate memory
void deallocateMemory(int processId) {
    int found = 0;

    for (int i = 0; i < MAX_MEMORY; i++) {
        if (memory[i] == processId) {
            memory[i] = -1;
            found = 1;
        }
    }

    if (found)
        printf("\nMemory released by Process %d\n", processId);
    else
        printf("\nProcess %d not found in memory\n", processId);
}

int main() {
    initializeMemory();
    displayMemory();

    allocateMemory(1, 200);
    displayMemory();

    allocateMemory(2, 300);
    displayMemory();

    deallocateMemory(1);
    displayMemory();

    allocateMemory(3, 400);
    displayMemory();

    return 0;
}

