#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block
struct Block {
    char data[256];          // Data stored in the block
    struct Block* next;      // Pointer to the next block
};

int main() {
    struct Block* firstBlock = NULL;  // Pointer to the first block
    struct Block* lastBlock = NULL;   // Pointer to the last block
    int blockCount = 0;               // Count of blocks
    int blockNumber;
    char data[256];
    char choice;

    printf("Linked Allocation Simulation\n");

    while (1) {
        printf("\nEnter 'W' to write a block, 'R' to read a block, or 'Q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q') {
            break;
        }

        if (choice == 'W' || choice == 'w') {
            printf("Enter data for the block: ");
            scanf(" %[^\n]", data);

            // Create a new block
            struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));

            for (int i = 0; i < 256; i++) {
                newBlock->data[i] = data[i];
            }
            newBlock->next = NULL;

            if (blockCount == 0) {
                firstBlock = newBlock;
                lastBlock = newBlock;
            } else {
                lastBlock->next = newBlock;
                lastBlock = newBlock;
            }

            blockCount++;
            printf("Block written successfully! Total blocks: %d\n", blockCount);
        }

        else if (choice == 'R' || choice == 'r') {
            if (blockCount == 0) {
                printf("No blocks available to read.\n");
                continue;
            }

            printf("Enter the block number to read (1-%d): ", blockCount);
            scanf("%d", &blockNumber);

            if (blockNumber < 1 || blockNumber > blockCount) {
                printf("Invalid block number. Valid range is 1-%d.\n", blockCount);
            } else {
                struct Block* currentBlock = firstBlock;
                for (int i = 1; i < blockNumber; i++) {
                    currentBlock = currentBlock->next;
                }
                printf("Block %d Data: %s\n", blockNumber, currentBlock->data);
            }
        }
    }

    // Free allocated memory
    struct Block* currentBlock = firstBlock;
    while (currentBlock != NULL) {
        struct Block* nextBlock = currentBlock->next;
        free(currentBlock);
        currentBlock = nextBlock;
    }

    return 0;
}

