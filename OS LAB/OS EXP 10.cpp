#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;

    // Producer writes message
    fp = fopen("msgqueue.txt", "w");
    fprintf(fp, "Hello, message queue!");
    fclose(fp);

    printf("Producer: Message sent.\n");

    // Consumer reads message
    char msg[100];
    fp = fopen("msgqueue.txt", "r");
    fgets(msg, sizeof(msg), fp);
    fclose(fp);

    printf("Consumer: Message received: %s\n", msg);

    return 0;
}
