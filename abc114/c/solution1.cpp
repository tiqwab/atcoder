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

// count of 7, 5, and 3
int dp1[20][20][20][20];
int dp2[20][20][20][20];

int main(void) {
    string S;
    cin >> S;
    int slen = (int) S.size();
    S = " " + S;

    dp1[0][0][0][0] = 1;
    for (int i = 1; i < slen; i++) {
        dp2[i][0][0][0] = 1;
    }
    for (int i = 0; i < slen; i++) {
        int d = S[i + 1] - '0';
        {
            for (int n1 = 0; n1 < slen; n1++) {
                for (int n2 = 0; n2 < slen; n2++) {
                    for (int n3 = 0; n3 < slen; n3++) {
                        // dp1
                        if (d == 3) {
#ifdef DEBUG
                            printf("[dp1 => dp1] i: %d, n1: %d, n2: %d, *n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                            dp1[i + 1][n1][n2][n3 + 1] += dp1[i][n1][n2][n3];
                        } else if (d == 5) {
#ifdef DEBUG
                            printf("[dp1 => dp1] i: %d, n1: %d, *n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                            dp1[i + 1][n1][n2 + 1][n3] += dp1[i][n1][n2][n3];
                        } else if (d == 7) {
#ifdef DEBUG
                            printf("[dp1 => dp1] i: %d, *n1: %d, n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                            dp1[i + 1][n1 + 1][n2][n3] += dp1[i][n1][n2][n3];
                        }
                        for (int j = 1; j < d; j++) {
                            if (j == 3) {
#ifdef DEBUG
                                printf("[dp1 => dp2] i: %d, n1: %d, n2: %d, *n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                                dp2[i + 1][n1][n2][n3 + 1] += dp1[i][n1][n2][n3];
                            } else if (j == 5) {
#ifdef DEBUG
                                printf("[dp1 => dp2] i: %d, n1: %d, *n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                                dp2[i + 1][n1][n2 + 1][n3] += dp1[i][n1][n2][n3];
                            } else if (j == 7) {
#ifdef DEBUG
                                printf("[dp1 => dp2] i: %d, *n1: %d, n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp1[i][n1][n2][n3]);
#endif 
                                dp2[i + 1][n1 + 1][n2][n3] += dp1[i][n1][n2][n3];
                            }
                        }

                        // dp2
#ifdef DEBUG
                        printf("[dp2 => dp2] i: %d, *n1: %d, n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp2[i][n1][n2][n3]);
#endif 
                        dp2[i + 1][n1 + 1][n2][n3] += dp2[i][n1][n2][n3];
#ifdef DEBUG
                        printf("[dp2 => dp2] i: %d, n1: %d, *n2: %d, n3: %d, += %d\n", i, n1, n2, n3, dp2[i][n1][n2][n3]);
#endif 
                        dp2[i + 1][n1][n2 + 1][n3] += dp2[i][n1][n2][n3];
#ifdef DEBUG
                        printf("[dp2 => dp2] i: %d, n1: %d, n2: %d, *n3: %d, += %d\n", i, n1, n2, n3, dp2[i][n1][n2][n3]);
#endif 
                        dp2[i + 1][n1][n2][n3 + 1] += dp2[i][n1][n2][n3];
                    }
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j < 19; j++) {
            for (int k = 1; k < 19; k++) {
                cnt += dp1[slen][i][j][k];
                cnt += dp2[slen][i][j][k];
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
