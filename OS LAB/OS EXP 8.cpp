#include <stdio.h>

int main() {
    int n, i, at[20], bt[20], rt[20], tq, time = 0, done = 0;
    int wt = 0, tat = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    scanf("%d", &tq);

    printf("P BT TAT WT\n");

    while (done < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                flag = 1;
                int exec = (rt[i] < tq) ? rt[i] : tq;
                rt[i] -= exec;
                time += exec;

                if (rt[i] == 0) {
                    done++;
                    int TAT = time - at[i];
                    int WT  = TAT - bt[i];
                    tat += TAT;
                    wt  += WT;
                    printf("%d %d %d %d\n", i+1, bt[i], TAT, WT);
                }
            }
        }
        if (!flag) time++; 
    }

    printf("Avg WT=%f\nAvg TAT=%f\n", (float)wt/n, (float)tat/n);
    return 0;
}
