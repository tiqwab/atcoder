#include <algorithm>
#include <iostream>
#include <vector>

#include <stdio.h>

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

    int a = (int) ((N * 100.0 + 108 - 1) / 108.0);
    // cout << a << endl;

    double c = ( a * 108.0 / 100.0);
    // printf("%f\n", N * 100.0 / 108.0);
    // printf("%f\n", c);

    int b = (int) c;

    if (N == b) {
        cout << a << endl;
    } else {
        cout << ":(" << endl;
    }
    
    return 0;
}
