#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek_time = 0, disk_size;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request_queue[n];

    printf("Enter the disk request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request_queue[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the disk size (maximum cylinder number): ");
    scanf("%d", &disk_size);

    // Sort request queue
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request_queue[i] > request_queue[j]) {
                int temp = request_queue[i];
                request_queue[i] = request_queue[j];
                request_queue[j] = temp;
            }
        }
    }

    printf("\nSCAN (Elevator) Disk Scheduling:\n");
    printf("Head Movement Sequence: %d", head);

    // Find position where head is located
    int index = 0;
    while (index < n && request_queue[index] < head) {
        index++;
    }

    // Move right first ? to the largest request
    for (int i = index; i < n; i++) {
        seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        printf(" -> %d", head);
    }

    // After reaching the end, move to disk boundary and reverse direction
    seek_time += abs(disk_size - 1 - head);
    head = disk_size - 1;
    printf(" -> %d", head);

    // Move left servicing remaining requests
    for (int i = index - 1; i >= 0; i--) {
        seek_time += abs(head - request_queue[i]);
        head = request_queue[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("Average Seek Time: %.2f\n", (float)seek_time / n);

    return 0;
}

