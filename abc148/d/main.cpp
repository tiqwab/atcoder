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

int solve(const int N, const vector<int> &a) {
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == cur + 1) {
            cur++;
        }
    }
    return cur;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int rems = solve(N, a);
    if (rems == 0) {
        cout << -1 << endl;
    } else {
        cout << N - rems << endl;
    }

    return 0;
}
