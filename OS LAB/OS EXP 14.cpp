#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF 4096

void createFile() {
    FILE *fp = fopen("C:/Users/itssk/OneDrive/Desktop/sasi.txt", "w");
    if (fp) {
        printf("File created successfully\n");
        fclose(fp);
    }
}

void copyFile() {
    int s = open("C:/Users/itssk/OneDrive/Desktop/sasi.txt", O_RDONLY);
    int d = open("C:/Users/itssk/OneDrive/Desktop/sk.txt",
                 O_WRONLY | O_CREAT | O_TRUNC, 0666);

    char buf[BUF];
    int r;

    while ((r = read(s, buf, BUF)) > 0)
        write(d, buf, r);

    close(s);
    close(d);
    printf("File copied successfully\n");
}

int main() {
    int ch;
    printf("1.Create  2.Copy  3.Delete\nEnter choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1: createFile(); break;
        case 2: copyFile(); break;
        case 3:
            if (remove("C:/Users/itssk/OneDrive/Desktop/sasi.txt") == 0)
                printf("Deleted successfully\n");
            else
                printf("Delete failed\n");
            break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
