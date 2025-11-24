#include <stdio.h>

int main() {
    int blockCount, fileCount;

    printf("Memory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &blockCount);

    printf("Enter the number of files: ");
    scanf("%d", &fileCount);

    int blocks[20], files[20], allocation[20], fragment[20];

    printf("\nEnter the size of the blocks:-\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blocks[i]);
    }

    printf("\nEnter the size of the files :-\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    for (int i = 0; i < fileCount; i++) {
        int worstIndex = -1;

        for (int j = 0; j < blockCount; j++) {
            if (blocks[j] >= files[i]) {
                if (worstIndex == -1 || blocks[j] > blocks[worstIndex]) {
                    worstIndex = j;
                }
            }
        }

        allocation[i] = worstIndex + 1;

        if (worstIndex != -1) {
            fragment[i] = blocks[worstIndex] - files[i];
            blocks[worstIndex] -= files[i];
        } else {
            fragment[i] = -1;
        }
    }

    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (int i = 0; i < fileCount; i++) {
        if (allocation[i] != 0)
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
                   i + 1, files[i], allocation[i], files[i] + fragment[i], fragment[i]);
        else
            printf("%d\t%d\t\tNot Allocated\n", i + 1, files[i]);
    }

    return 0;
}

