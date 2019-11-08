#include <stdbool.h>
#include <stdio.h>

#define MAX_N 1000

int n;
int plan[MAX_N][MAX_N - 1];
int players[MAX_N];

int solve() {
    bool has_match = false;
    int days = 0;
    while (true) {
        days++;

        for (int i = 0; i < n; i++) {
            int p1 = i + 1;
            if (players[p1 - 1] < 0 || players[p1 - 1] > n - 1) {
                continue;
            }
            int p2 = plan[p1 - 1][players[p1 - 1]];
            if (plan[p2 - 1][players[p2 - 1]] != p1) {
                continue;
            }
            // minus means the process for this player is finished
            players[p1 - 1] = -1 * (players[p1 - 1] + 1);
            players[p2 - 1] = -1 * (players[p2 - 1] + 1);
            has_match = true;
        }

        if (!has_match) {
            return -1;
        }

        bool completed = true;
        for (int i = 0; i < n; i++) {
            if (players[i] < 0) {
                players[i] *= -1;
            }
            if (players[i] < n - 1) {
                completed = false;
            }
        }

        if (completed) {
            return days;
        }
    }
}

int main(void) {
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int x;
            scanf("%d", &x);
            plan[i][j] = x;
        }
    }

    printf("%d\n", solve());

    return 0;
}
