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

vector<int> H;

int main(void) {
    int N, K;
    cin >> N >> K;

    H.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    sort(H.begin(), H.end());

    ll acc = 0;
    for (int i = 0; i < N - K; i++) {
        acc += H[i];
    }

    cout << acc << endl;
    
    return 0;
}
