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

int solve(vector<vector<int>> lights, vector<int> ps, int N, int M) {
    int count = 0;

    for (int bits = 0; bits <= ((1 << N) - 1); bits++) {
        bool ok = true;
        for (int i = 0; i < M; i++) {
            int c = 0;
            for (int j = 0; j < (int) lights[i].size(); j++) {
                int s = lights[i][j];
                if (bits & (1 << s)) {
                    c++;
                }
            }
            // printf("bits: 0x%x, i: %d, c: %d\n", bits, i, c);
            if (c % 2 != ps[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            count++;
        }
    }

    return count;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> lights;
    lights.resize(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            s--;
            lights[i].push_back(s);
        }
    }

    vector<int> ps;
    ps.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> ps[i];
    }

    cout << solve(lights, ps, N, M) << endl;

    return 0;
}
