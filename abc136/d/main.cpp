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

const int MAX_S = 100000;
char S[MAX_S + 1];

void solve(const int N) {
    vector<int> dist(N);

    int prev = 0;
    int cur = 1;
    char dir = 'R';
    while (cur <= N) {
        if (S[cur] != dir || cur == N) {
            for (int i = prev; i < cur; i++) {
                if (dir == 'R') {
                    dist[i] = cur - i - 1;
                } else {
                    dist[i] = -1 * (i - prev + 1);
                }
            }
            dir = S[cur];
            prev = cur;
        }
        cur++;
    }

    // for (int i = 0; i < N; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    vector<int> count(N, 0);
    for (int i = 0; i < N; i++) {
        if (abs(dist[i]) % 2 == 0) {
            count[i + dist[i]]++;
        } else {
            count[i + dist[i] + 1]++;
        }
    }

    cout << count[0];
    for (int i = 1; i < N; i++) {
        cout << " " << count[i];
    }
    cout << endl;
}

int main(void) {
    cin >> S;
    int N = strlen(S);

    solve(N);

    return 0;
}
