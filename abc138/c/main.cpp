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

    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double prev = v[0];
    for (int i = 1; i < N; i++) {
        prev = (prev + v[i]) / 2;
    }

    printf("%3.6f\n", prev);
    
    return 0;
}
