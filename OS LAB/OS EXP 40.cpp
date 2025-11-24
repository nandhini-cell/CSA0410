#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <sys/stat.h>

int main() {
    char filename[] = "file.txt";

    // Read + Write permissions for user
    int new_permissions = _S_IREAD | _S_IWRITE;

    if (_chmod(filename, new_permissions) == 0) {
        printf("File permissions changed successfully.\n");
    } else {
        perror("_chmod");
        return 1;
    }

    return 0;
}

