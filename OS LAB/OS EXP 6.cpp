#include <stdio.h>

int main() {
    int n, i, qt, at[20], bt[20], rt[20], time = 0, done = 0;
    int wt = 0, tat = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    scanf("%d", &qt);

    printf("P BT TAT WT\n");

    while (done < n) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                int exec = (rt[i] < qt) ? rt[i] : qt;
                time += exec;
                rt[i] -= exec;

                if (rt[i] == 0) {
                    done++;
                    int TAT = time - at[i];
                    int WT = TAT - bt[i];
                    tat += TAT;
                    wt += WT;
                    printf("%d %d %d %d\n", i+1, bt[i], TAT, WT);
                }
            }
        }
    }

    printf("Avg WT = %f\n", (float)wt / n);
    printf("Avg TAT = %f\n", (float)tat / n);
    return 0;
}
