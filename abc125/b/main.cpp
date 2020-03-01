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

int main(void) {
    int N;
    vector<int> V;
    vector<int> C;

    cin >> N;

    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    C.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (V[i] > C[i]) {
            ans += V[i] - C[i];
        }
    }

    cout << ans << endl;

    return 0;
}
