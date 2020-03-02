#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

bool solve(vector<vector<int>> &A, const vector<int> b, const int N) {
    vector<vector<bool>> flag(3, vector<bool>(3, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (A[j][k] == b[i]) {
                    flag[j][k] = true;
                }
            }
        }
    }

    // yoko
    for (int i = 0; i < 3; i++) {
        if (flag[i][0] && flag[i][1] && flag[i][2]) {
            return true;
        }
    }
    
    // tate
    for (int i = 0; i < 3; i++) {
        if (flag[0][i] && flag[1][i] && flag[2][i]) {
            return true;
        }
    }

    // right down
    if (flag[0][0] && flag[1][1] && flag[2][2]) {
        return true;
    }

    // left down
    if (flag[0][2] && flag[1][1] && flag[2][0]) {
        return true;
    }


    return false;
}

int main(void) {
    vector<vector<int>> A(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            A[i][j] = a;
        }
    }

    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    if (solve(A, b, N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
