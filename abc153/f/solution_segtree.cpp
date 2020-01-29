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

// ref. arihon 3-3
// E: type of data, R: type of query result
template<typename E, typename R>
class SegmentTree {
    public:
        SegmentTree(const int _n, const E inf, R (*f)(E, E)): f(f), inf(inf) {
            n = 1;
            while (n < _n) n *= 2;
            data.resize(2 * n, inf);
        }

        // update data[k] with a
        // time complexity: O(n)
        void update(int k, E a) {
            k += n - 1;
            data[k] = a;
            while (k > 0) {
                k = (k - 1) / 2;
                data[k] = (*f)(data[k * 2 + 1], data[k * 2 + 2]);
            }
        }

        // query value from [a, b)
        // // time complexity: O(n)
        R query(int a, int b) {
            return query(a, b, 0, 0, n);
        }

    private:
        int n;
        R (*f)(E, E);
        const E inf;
        vector<E> data;

        R query(int a, int b, int k, int l, int r) {
            // if [a, b) intersect [l, r) = empty
            if (r <= a || b <= l) {
                return inf;
            }

            // if [a, b) includes [l, r)
            if (a <= l && r <= b) {
                return data[k];
            } else {
                R vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
                R vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
                return (*f)(vl, vr);
            }
        }
};

// {position, hp}
vector<pair<int, int>> enemies;

ll solve(SegmentTree<ll, ll> * const st, const int N, const int D, const int A) {
    ll count = 0LL;
    for (int i = 0; i < N; i++) {
        pair<int, int> enemy = enemies[i];
        const pair<int, int> target = {enemy.first - 2 * D, -1};
        auto p = lower_bound(enemies.begin(), enemies.begin() + i, target,
                [](const pair<int, int> &x, const pair<int, int> &y) {
                    return x.first < y.first;
                });
        // printf("query(%d, %d)\n", p->first, enemy.first);
        ll sum = st->query(p - enemies.begin(), i);
        ll hp = enemy.second;
        hp -= sum * A;
        if (hp > 0) {
            ll k = (hp - 1 + A) / A;
            // printf("i: %d, sum: %lld, k: %lld\n", i, sum, k);
            count += k;
            // printf("update(%d, %d)\n", enemy.first, k);
            st->update(i, k);
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

    auto f = [](ll x, ll y) {
        return x + y;
    };
    SegmentTree<ll, ll> *st = new SegmentTree<ll, ll>(N + 1, 0LL, f);

    cout << solve(st, N, D, A) << endl;

    delete st;
    return 0;
}
