#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

vector<int> as;

void f(const int N) {
    vector<int> ops(N + 1, 0);
    for (int i = 0; i < N; i++) {
        ops[max(0, i - as[i])]++;
        ops[min(N, i + as[i] + 1)]--;
    }

    int light = 0;
    for (int i = 0; i < N; i++) {
        light += ops[i];
        as[i] = light;
    }
}

void solve(const int N, const int K) {
    for (int i = 0; i < K; i++) {
        f(N);

        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (as[i] < N) {
                ok = false;
                break;
            }
        }
        if (ok) {
            break;
        }
    }
}

int main(void) {
    int N, K;
    cin >> N >> K;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    solve(N, K);

    cout << as[0];
    for (int i = 1; i < N; i++) {
        cout << " " << as[i];
    }
    cout << endl;

    return 0;
}
