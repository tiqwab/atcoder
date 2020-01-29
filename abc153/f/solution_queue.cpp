#include <algorithm>
#include <iostream>
#include <queue>
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

// {position, hp}
vector<pair<int, int>> enemies;

ll solve(const int N, const int D, const int A) {
    // {postion, effect}
    queue<pair<int, int>> q;
    ll count = 0;
    ll effect = 0;

    for (int i = 0; i < N; i++) {
        auto enemy = enemies[i];
        ll hp = enemy.second;
        while (!q.empty()) {
            auto p = q.front();
            if (enemy.first > p.first) {
                effect -= p.second;
                q.pop();
            } else {
                break;
            }
        }

        hp -= effect;
        if (hp > 0) {
            ll k = (hp + A - 1LL) / A;
            count += k;
            effect += A * k;
            q.push({enemy.first + 2 * D, A * k});
        }
    }

    return count;
}

int main(void) {
    int N, D, A;
    cin >> N >> D >> A;

    enemies.resize(N);
    for (int i = 0; i < N; i++) {
        int x, h;
        cin >> x >> h;
        enemies[i] = {x, h};
    }
    sort(enemies.begin(), enemies.end());

    cout << solve(N, D, A) << endl;

    return 0;
}
