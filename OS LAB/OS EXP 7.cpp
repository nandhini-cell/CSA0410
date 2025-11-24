#include <stdio.h>

int main() {
    int n, i, j, at[20], bt[20], pr[20], done = 0, time = 0;
    int wt = 0, tat = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &at[i], &bt[i]);
        pr[i] = i + 1;
    }

    while (done < n) {
        int idx = -1, min_bt = 9999;
        for (i = 0; i < n; i++)
            if (at[i] <= time && bt[i] > 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }

        if (idx == -1) { time++; continue; }

        time += bt[idx];
        int TAT = time - at[idx];
        int WT  = TAT - bt[idx];
        tat += TAT;
        wt  += WT;

        printf("P%d AT=%d BT=%d TAT=%d WT=%d\n", pr[idx], at[idx], bt[idx], TAT, WT);
        bt[idx] = 0;
        done++;
    }

    printf("Avg WT=%f\nAvg TAT=%f\n", (float)wt/n, (float)tat/n);
    return 0;
}
