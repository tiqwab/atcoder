#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000001
using namespace std;

using Matrix = vector<vector<int>>;
using Path = vector<int>;

Matrix matrix;
vector<Path> paths;

void warshall_floyd(Matrix &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (matrix[j][k] > matrix[j][i] + matrix[i][k]) {
                    // printf("i=%d, j=%d, k=%d, matrix[j][k]=%d, matrix[j][i]=%d, matrix[i][k]=%d\n",
                    //         i, j, k, matrix[j][k], matrix[j][i], matrix[i][k]);
                    matrix[j][k] = matrix[j][i] + matrix[i][k];

                    paths[j * n + k].clear();
                    auto it = paths[j * n + i].begin();
                    while (it != paths[j * n + i].end()) {
                        paths[j * n + k].push_back(*it++);
                    }
                    paths[j * n + k].push_back(i + 1);
                    it = paths[i * n + k].begin();
                    while (it != paths[i * n + k].end()) {
                        paths[j * n + k].push_back(*it++);
                    }
                }
            }
        }
    }
}

int can_reach(const int src, const int dest, const Path &path, const int l) {
    int count = 0;
    int remain = l;

    Path p = Path(path);
    p.push_back(dest);

    int s = src, t;
    auto it = p.begin();
    while (it != p.end()) {
        t = *it++;
        // cout << s << ", " << t << ", " << remain << endl;
        int d = matrix[s-1][t-1];
        if (d == INF) {
            // not reachable
            return -1;
        }
        if (d > l) {
            // distance is larger than the maximum available gasoline
            return -1;
        }
        if (d > remain) {
            remain = l;
            count++;
        }
        remain -= d;
        s = t;
    }

    return count;
}

int main(void) {
    int n, m, l;
    cin >> n >> m >> l;

    matrix = Matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i] = vector<int>(n, INF);
        matrix[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        matrix[a-1][b-1] = c;
        matrix[b-1][a-1] = c;
    }

    paths = vector<Path>(n * n);
    for (int i = 0; i < n; i++) {
        paths[i] = Path();
        // for (int j = 0; j < n; j++) {
        //     paths[i * n + j].push_back(i + 1);
        // }
    }

    warshall_floyd(matrix);

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << i+1 << "->" << j+1 << ": ";
    //         auto it = paths[i * n + j].begin();
    //         while (it != paths[i * n + j].end()) {
    //             cout << *it++ << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        if (matrix[s-1][t-1] != INF) {
            int count = can_reach(s, t, paths[(s-1) * n + (t-1)], l);
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
