#include <stdio.h>
#include <string.h>

int main() {
    char filename[50], pattern[50], line[200];
    FILE *fp;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    printf("\nLines containing the pattern \"%s\":\n\n", pattern);

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern) != NULL) {   // check if pattern is in line
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}

