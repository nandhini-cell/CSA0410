#include <stdio.h>
#define MAX_FRAMES 3  // Maximum number of frames

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);

    int frames[MAX_FRAMES];
    int framePointer = 0;
    int pageFaults = 0;

    // Initialize frames
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n\nPage Replacement Order:\n");

    // FIFO page replacement logic
    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if page is already present
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        // If page is not found -> page fault
        if (!pageFound) {
            printf("Page %d -> ", page);
            frames[framePointer] = page;
            framePointer = (framePointer + 1) % MAX_FRAMES;
            printFrames(frames, MAX_FRAMES);
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}

