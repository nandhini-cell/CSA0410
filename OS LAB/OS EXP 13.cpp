#include <stdio.h>

void firstFit(int mp[], int p[], int m, int n) {
    for (int i = 0; i < n; i++) {
        int allocated = 0;
        for (int j = 0; j < m; j++) {
            if (mp[j] >= p[i]) {
                printf("Process %d (%d KB) -> Partition %d (%d KB)\n",
                       i, p[i], j, mp[j]);
                mp[j] -= p[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated)
            printf("Process %d (%d KB) -> NOT allocated\n", i, p[i]);
    }
}

void bestFit(int mp[], int p[], int m, int n) {
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (mp[j] >= p[i] && (best == -1 || mp[j] < mp[best]))
                best = j;
        }
        if (best != -1) {
            printf("Process %d (%d KB) -> Partition %d (%d KB)\n",
                   i, p[i], best, mp[best]);
            mp[best] -= p[i];
        } else
            printf("Process %d (%d KB) -> NOT allocated\n", i, p[i]);
    }
}

void worstFit(int mp[], int p[], int m, int n) {
    for (int i = 0; i < n; i++) {
        int worst = -1;
        for (int j = 0; j < m; j++) {
            if (mp[j] >= p[i] && (worst == -1 || mp[j] > mp[worst]))
                worst = j;
        }
        if (worst != -1) {
            printf("Process %d (%d KB) -> Partition %d (%d KB)\n",
                   i, p[i], worst, mp[worst]);
            mp[worst] -= p[i];
        } else
            printf("Process %d (%d KB) -> NOT allocated\n", i, p[i]);
    }
}

int main() {
    int m, n, mp[20], p[20], ch;

    printf("Enter number of partitions: ");
    scanf("%d", &m);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter memory partitions:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &mp[i]);

    printf("Enter process sizes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("\n1.First Fit  2.Best Fit  3.Worst Fit\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1) firstFit(mp, p, m, n);
    else if (ch == 2) bestFit(mp, p, m, n);
    else if (ch == 3) worstFit(mp, p, m, n);
    else printf("Invalid choice");
    
    return 0;
}
