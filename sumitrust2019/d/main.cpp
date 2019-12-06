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

const int MAX_N = 30000;

int N;
char S[MAX_N + 1];
bool numbers[1000];

void solve() {
    char str[4];
    for (int i = 0; i < 1000; i++) {
        int ind_i = 0;
        snprintf(str, 4, "%03d", i);
        for (int j = 0; j < N; j++) {
            if (str[ind_i] == S[j]) {
                ind_i++;
                if (ind_i == 3) {
                    numbers[i] = true;
                    break;
                }
            }
        }
    }
}

int main(void) {
    cin >> N;
    cin >> S;

    solve();

    int count = 0;
    for (int i = 0; i <= 1000; i++) {
        if (numbers[i]) {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}
