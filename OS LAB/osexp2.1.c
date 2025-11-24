#include <stdio.h>

int main() {
    FILE *src, *dest;
    char srcname[100], destname[100], ch;

    printf("Enter source file name: ");
    scanf("%s", srcname);

    src = fopen(srcname, "r");
    if (!src) {
        printf("Cannot open %s\n", srcname);
        return 0;
    }

    printf("Enter destination file name: ");
    scanf("%s", destname);

    dest = fopen(destname, "w");
    if (!dest) {
        printf("Cannot open %s\n", destname);
        return 0;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("Contents copied to %s\n", destname);

    fclose(src);
    fclose(dest);
    return 0;
}

