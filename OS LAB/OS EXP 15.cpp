#include <stdio.h>

int main() {

    FILE *fp = fopen("C:/Users/itssk/OneDrive/Desktop/example.txt", "w");

    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    fprintf(fp, "This is an example file content.");
    fclose(fp);

    printf("File created successfully!\n");
    return 0;
}

