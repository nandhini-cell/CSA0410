#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int main() {
    int frames[MAX_FRAMES];
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;  // Initialize to empty frames
    }

    int pageFaults = 0;

    int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);

    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", referenceString[i]);
    }

    printf("\n\nPage Replacement Order:\n");

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if page already exists in frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            printf("Page %d -> ", page);
            int replaceIndex = -1;

            // Check if empty frame exists
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find optimal victim page
            if (replaceIndex == -1) {
                int farthestDistance = -1;

                for (int j = 0; j < MAX_FRAMES; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == referenceString[k])
                            break;
                    }

                    if (k > farthestDistance) {
                        farthestDistance = k;
                        replaceIndex = j;
                    }
                }
            }

            frames[replaceIndex] = page;
            printFrames(frames, MAX_FRAMES);
            pageFaults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}

