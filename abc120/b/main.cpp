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
    int A, B, K;
    cin >> A >> B  >> K;

    int count = 0;
    int ans = 0;
    for (int i = min(A, B); i >= 0; i--) {
        if (A % i == 0 && B % i == 0) {
            count++;
            if (count == K) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
