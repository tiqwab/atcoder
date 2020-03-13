#include <iostream>

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

double calc(const int i, const int n, const int *a) {
    double acc = 1;
    for (int j = 0; j < n; j++) {
        if (j == i) continue;
        acc *= a[j];
    }
    return acc;
}

int main(void) {
    int N;
    int a[MAX_N];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    double acc = 0;
    for (int i = 0; i < N; i++) {
        acc += calc(i, N, a);
    }

    printf("%9.6f\n", calc(-1, N, a) / acc);
    
    return 0;
}
