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
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int max_h = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] >= max_h) {
            ans++;
            max_h = H[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}
