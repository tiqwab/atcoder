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

    int minimum = 1000;
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        chmin(minimum, a);
        chmax(maximum, a);
    }

    cout << maximum - minimum << endl;

    return 0;
}
