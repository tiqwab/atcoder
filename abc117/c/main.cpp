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

vector<int> X;
vector<int> L;

int main(void) {
    int N, M;
    cin >> N >> M;

    if (N >= M) {
        cout << "0" << endl;
        return 0;
    }

    X.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());

    L.resize(M - 1);
    for (int i = 0; i < M - 1; i++) {
        L[i] = X[i + 1] - X[i];
    }
    sort(L.begin(), L.end());

    ll acc = 0;
    for (int i = 0; i < M - N; i++) {
        acc += L[i];
    }

    cout << acc << endl;

    return 0;
}
