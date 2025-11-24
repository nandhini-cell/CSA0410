#include <stdio.h>

int main() {
    int p[100][4], n, i, j, temp;
    float avg_wt = 0, avg_tat = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) { 
        scanf("%d", &p[i][1]); 
        p[i][0] = i + 1; 
    }

    for (i = 0; i < n; i++)              // Sort by BT
        for (j = i + 1; j < n; j++)
            if (p[j][1] < p[i][1]) {
                temp = p[i][1]; p[i][1] = p[j][1]; p[j][1] = temp;
                temp = p[i][0]; p[i][0] = p[j][0]; p[j][0] = temp;
            }

    p[0][2] = 0;
    for (i = 1; i < n; i++) {            // WT
        p[i][2] = p[i - 1][2] + p[i - 1][1];
        avg_wt += p[i][2];
    }
    avg_wt /= n;

    printf("P BT WT TAT\n");
    for (i = 0; i < n; i++) {            // TAT
        p[i][3] = p[i][1] + p[i][2];
        avg_tat += p[i][3];
        printf("P%d %d %d %d\n", p[i][0], p[i][1], p[i][2], p[i][3]);
    }
    avg_tat /= n;

    printf("Avg WT=%f\nAvg TAT=%f", avg_wt, avg_tat);
    return 0;
}
