#include <stdio.h>

struct PS {
    char name;
    int bt, wt, tat, pr;
};

int main() {
    int n, i, j, pos, total = 0;
    float avg_wt, avg_tat;
    scanf("%d", &n);

    struct PS p[n], temp;
    for (i = 0; i < n; i++) {
        p[i].name = 'A' + i;
        scanf("%d%d", &p[i].bt, &p[i].pr);
    }

    for (i = 0; i < n; i++) {                 // sort by priority (high first)
        pos = i;
        for (j = i + 1; j < n; j++)
            if (p[j].pr > p[pos].pr) pos = j;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    p[0].wt = 0;
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        total += p[i].wt;
    }
    avg_wt = (float) total / n;

    total = 0;
    printf("P BT WT TAT\n");
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        total += p[i].tat;
        printf("%c %d %d %d\n", p[i].name, p[i].bt, p[i].wt, p[i].tat);
    }

    avg_tat = (float) total / n;
    printf("Avg WT=%f\nAvg TAT=%f", avg_wt, avg_tat);
    return 0;
}
