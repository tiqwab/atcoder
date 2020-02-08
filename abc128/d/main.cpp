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

vector<int> V;

ll solve(const int N, const int K) {
    const int R = min(N, K);
    ll ans = 0LL;

    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= R - i; j++) {
            for (int k = 0; k <= K - (i + j); k++) {
                vector<int> jewels;
                for (int l = 0; l < i; l++) {
                    jewels.push_back(V[l]);
                }
                for (int r = N - 1; r >= N - j; r--) {
                    jewels.push_back(V[r]);
                }
                sort(jewels.begin(), jewels.end());
                reverse(jewels.begin(), jewels.end());
                int size = (int) jewels.size();
                for (int x = 0; x < min(size, k); x++) {
                    if (jewels.back() > 0) {
                        break;
                    }
                    jewels.pop_back();
                }

                ll acc = 0LL;
                for (int x = 0; x < (int) jewels.size(); x++) {
                    acc += jewels[x];
                }
                // printf("i: %d, j: %d, k: %d, acc: %lld\n", i, j, k, acc);
                chmax(ans, acc);
            }
        }
    }

    return ans;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    V.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    cout << solve(N, K) << endl;

    return 0;
}
