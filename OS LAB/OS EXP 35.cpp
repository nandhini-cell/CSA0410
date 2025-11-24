#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block in the file
struct Block {
    int blockNumber;
    char data[256];  // Adjust size as required
};

int main() {
    FILE *file;
    struct Block block;
    int blockNumber;

    // Index block that stores file pointers (byte offsets)
    long indexBlock[100] = {0};   // supports block numbers 1–99

    // Open file to write blocks
    file = fopen("indexed_file.txt", "wb");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Write blocks sequentially and update index block
    printf("Enter blocks (Enter '0' as block number to exit):\n");
    while (1) {
        printf("Block Number: ");
        scanf("%d", &block.blockNumber);

        if (block.blockNumber == 0) {
            break;
        }

        printf("Data: ");
        scanf(" %[^\n]", block.data);

        // Record pointer before writing data to file
        indexBlock[block.blockNumber] = ftell(file);

        // Write the block to file
        fwrite(&block, sizeof(struct Block), 1, file);
    }

    fclose(file);

    // Open file again for reading
    file = fopen("indexed_file.txt", "rb");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    // Read request loop
    while (1) {
        printf("\nEnter the block number to read (0 to exit): ");
        scanf("%d", &blockNumber);

        if (blockNumber == 0) {
            break;
        }

        if (indexBlock[blockNumber] == 0) {
            printf("Block not found or empty.\n");
        } else {
            // Move to stored location
            fseek(file, indexBlock[blockNumber], SEEK_SET);

            // Read the block
            fread(&block, sizeof(struct Block), 1, file);

            printf("\nBlock Number: %d\n", block.blockNumber);
            printf("Data: %s\n", block.data);
        }
    }

    fclose(file);
    return 0;
}

