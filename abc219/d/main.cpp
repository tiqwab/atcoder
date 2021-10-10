#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

const int INF = INT_MAX / 2;
const int MAX_X = 300;
const int MAX_Y = 300;

// {tako, tai}
vector<pair<int,int>> lunches;

vector<vector<int>> dp;

int main(void) {
    int N;
    cin >> N;
    int X, Y;
    cin >> X >> Y;

    lunches.resize(N);
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        lunches[i] = make_pair(A, B);
    }

    dp.resize(MAX_X + 1, vector<int>(MAX_Y + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        auto lunch = lunches[i];
        for (int j = MAX_X; j >= 0 ; j--) {
            for (int k = MAX_Y; k >= 0; k--) {
                const int next_j = min(X, j + lunch.first);
                const int next_k = min(Y, k + lunch.second);
                if (dp[j][k] != INF) {
                    chmin(dp[next_j][next_k], dp[j][k] + 1);
                }
            }
        }
    }

#ifdef DEBUG
    printf("dp: \n");
    for (int i = 0; i <= X; i++) {
        for (int j = 0; j <= Y; j++) {
            printf("%10d ", dp[i][j]);
        }
        printf("\n");
    }
#endif

    if (dp[X][Y] != INF) {
        cout << dp[X][Y] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
