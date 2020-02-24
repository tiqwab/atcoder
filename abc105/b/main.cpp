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

    // vector<bool> a(N + 1, false);

    int count = 0;
    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= 14; j++) {
            int x = i * 4 + j * 7;
            if (x == N) {
                count++;
            }
        }
    }

    if (count > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
