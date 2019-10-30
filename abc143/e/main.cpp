#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 305

typedef long long ll;
const ll INF = 1e17;
// using Matrix = vector<vector<ll>>;
using Matrix = ll[MAX_N][MAX_N];

Matrix matrix;

void warshall_floyd(Matrix &matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (matrix[j][i] != INF && matrix[i][k] != INF) {
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
                }
            }
        }
    }
}

int main(void) {
    int n, m, l;
    cin >> n >> m >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = INF;
        }
        matrix[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = c;
        matrix[b-1][a-1] = c;
    }

    warshall_floyd(matrix, n);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (matrix[i][j] <= l) {
                    matrix[i][j] = 1LL;
                } else {
                    matrix[i][j] = INF;
                }
            }
        }
    }

    warshall_floyd(matrix, n);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        if (matrix[s-1][t-1] != INF) {
            cout << (matrix[s-1][t-1] - 1) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
