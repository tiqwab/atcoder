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
    cin >> N;

    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());

    ll acc = 0;
    const int len = (int) L.size();
    for (int i = 0; i < len - 1; i++) {
        acc += L[i];
    }

    if (acc > L[len - 1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
