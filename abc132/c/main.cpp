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

int solve(const int N, const vector<int> &d) {
    int a = d[N / 2 - 1];
    int b = d[N / 2];

    return b - a;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    cout << solve(N, d) << endl;
    
    return 0;
}

