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

const int MAX_N = 100;

int main(void) {
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    char U[MAX_N * 2 + 1];
    for (int i = 0; i < N; i++) {
        U[i * 2] = S[i];
        U[i * 2 + 1] = T[i];
    }
    U[N * 2] = 0;

    fputs(U, stdout);
    cout << endl;
    
    return 0;
}
