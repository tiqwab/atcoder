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

    int count = 0;
    N = min(N, 99999);
    if (N >= 10000) {
        count += N - 10000 + 1;
    }
    N = min(N, 999);
    if (N >= 100) {
        count += N - 100 + 1;
    }
    N = min(N, 9);
    if (N > 0) {
        count += N;
    }

    cout << count << endl;
    
    return 0;
}
