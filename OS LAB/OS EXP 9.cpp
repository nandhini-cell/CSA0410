#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w");
    fprintf(fp, "Hello Shared Memory Alternative");
    fclose(fp);

    printf("Data written to file.\n");
    return 0;
}
