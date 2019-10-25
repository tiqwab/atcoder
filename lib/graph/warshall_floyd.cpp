#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000000000

using namespace std;

typedef vector<vector<long> > Matrix;
// using Matrix = vector<vector<int>>;

void warshall_floyd(Matrix &matrix) {
    int n = matrix.size();

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
    int v, e;
    cin >> v >> e;

    Matrix matrix(v);
    for (int i = 0; i < v; i++) {
        matrix[i] = vector<long>(v, INF);
        matrix[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        matrix[s][t] = d;
    }

    warshall_floyd(matrix);

    for (int i = 0; i < v; i++) {
        if (matrix[i][0] < INF) {
            cout << matrix[i][0];
        } else {
            cout << "INF";
        }
        for (int j = 1; j < v; j++){ 
            if (matrix[i][j] < INF) {
                cout << " " << matrix[i][j];
            } else {
                cout << " " << "INF";
            }
        }
        cout << endl;
    }

    return 0;
}

