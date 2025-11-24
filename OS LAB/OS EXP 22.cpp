#include <stdio.h>

#define MAX_MEMORY 1000

int memory[MAX_MEMORY];

// Initialize memory to -1 (free)
void initializeMemory() {
    for (int i = 0; i < MAX_MEMORY; i++) {
        memory[i] = -1;
    }
}

// Display free memory blocks
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

// Best-Fit Allocation
void allocateMemory(int processId, int size) {
    int bestStart = -1;
    int bestSize = MAX_MEMORY + 1;

    int i = 0;
    while (i < MAX_MEMORY) {
        if (memory[i] == -1) {
            int start = i;
            int blockSize = 0;

            while (i < MAX_MEMORY && memory[i] == -1) {
                blockSize++;
                i++;
            }

            if (blockSize >= size && blockSize < bestSize) {
                bestStart = start;
                bestSize = blockSize;
            }
        } else {
            i++;
        }
    }

    if (bestStart != -1) {
        for (int j = bestStart; j < bestStart + size; j++) {
            memory[j] = processId;
        }
        printf("\nAllocated block %d - %d to Process %d\n",
               bestStart, bestStart + size - 1, processId);
    } else {
        printf("\nAllocation FAILED for Process %d (Not enough space)\n", processId);
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

    if (found) {
        printf("\nMemory released by Process %d\n", processId);
    } else {
        printf("\nProcess %d not found in memory.\n", processId);
    }
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

