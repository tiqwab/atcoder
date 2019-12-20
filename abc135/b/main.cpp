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

const int MAX_N = 50;

int main(void) {
    int N;
    cin >> N;

    int A[MAX_N];
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] != i + 1) {
            count++;
        }
    }

    if (count > 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
