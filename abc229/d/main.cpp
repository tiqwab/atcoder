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

int main(void) {
    string S;
    cin >> S;
    int K;
    cin >> K;

    // x > 0 if '#', x < 0 if '.'
    deque<pair<char, int>> balls;
    {
        char prev = S[0];
        int cnt = 1;
        for (int i = 1; i < (int) S.size(); i++) {
            if (S[i] == prev) {
                cnt++;
            } else {
                balls.push_back(make_pair(prev, cnt));
                prev = S[i];
                cnt = 1;
            }
        }
        balls.push_back(make_pair(prev, cnt));

#ifdef DEBUG
        printf("balls: \n");
        for (auto p : balls) {
            printf("  (%c, %d)\n", p.first, p.second);
        }
#endif
    }

    if (K == 0) {
        int ans = 0;
        for (auto ball : balls) {
            if (ball.first == 'X') {
                chmax(ans, ball.second);
            }
        }
        printf("%d\n", ans);
        return 0;
    }

    deque<pair<char, int>> used;

    int ans = 0;
    int acc = 0;
    int k = 0;

    while (!balls.empty()) {
        auto cur_ball = balls.front();
        const char c = cur_ball.first;
        const int d = cur_ball.second;

#ifdef DEBUG
        printf("cur_ball: (%c, %d), acc: %d, k: %d\n", c, d, acc, k);
        printf("used: ");
        for (auto p : used) {
            printf("(%c, %d) ", p.first, p.second);
        }
        printf("\n");
#endif

        if (c == 'X') {
            used.push_back(cur_ball);
            balls.pop_front();
            acc += d;
        } else {
            if (k + d <= K) {
                used.push_back(cur_ball);
                balls.pop_front();
                acc += d;
                k += d;
            } else {
                if (k == K) {
                    auto first_ball = used.front();
                    used.pop_front();
                    acc -= first_ball.second;
                    if (first_ball.first == '.') {
                        k -= first_ball.second;
                    }
                } else {
                    balls.pop_front();
                    balls.push_front(make_pair(c, d - (K - k)));
                    used.push_back(make_pair(c, K - k));
                    acc += K - k;
                    k += K - k;
                }
            }
        }

        chmax(ans, acc);
    }

    cout << ans << endl;

    return 0;
}
