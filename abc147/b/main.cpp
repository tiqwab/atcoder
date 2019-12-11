#include <algorithm>
#include <iostream>
#include <vector>

#include <string.h>

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

const int MAX_S = 100;

int main(void) {
    char S[MAX_S + 1];
    cin >> S;
    int N;
    N = strlen(S);

    int count = 0;
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - 1 - i]) {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}
