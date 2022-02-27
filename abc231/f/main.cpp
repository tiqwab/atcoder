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

vector<pair<int, int>> presents;

map<int, int> value_to_id;

int get_id(const int value) {
    static int id = 0;
    if (value_to_id.find(value) == value_to_id.end()) {
        value_to_id[value] = id++;
    }
    return value_to_id[value];
}

ll add_for_same_presents() {
    map<pair<int, int>, ll> present_to_cnt;
    for (auto p : presents) {
        present_to_cnt[p] += 1;
    }
    ll ans = 0;
    for (auto c : present_to_cnt) {
        const ll cnt = c.second;
        if (cnt > 1) {
            ans += cnt * (cnt - 1) / 2;
        }
    }
    return ans;
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
        // 0-index, [0, _n) in other words
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
        // 0-index, [0, _n) in other words
        // time complexity: O(n)
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

const int MAX_N = 200000;

int main(void) {
    int N;
    cin >> N;

    vector<int> set_b;

    presents.resize(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        presents[i].first = a;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        presents[i].second = b;

        set_b.push_back(b);
    }

    // calculate value_to_id
    sort(set_b.begin(), set_b.end());
    for (int i = 0; i < (int) set_b.size(); i++) {
        value_to_id[set_b[i]] = i;
    }

    // setup segment tree
    auto f = [](int x, int y) {
        return x + y;
    };
    SegmentTree<int, int> *st = new SegmentTree<int, int>(N, 0, f);

    for (int i = 0; i < N; i++) {
        const int id = value_to_id[presents[i].second];
        st->update(id, st->query(id, id + 1) + 1);
    }

    // sort presents
    sort(presents.begin(), presents.end(), [](const auto &one, const auto &two) {
        if (one.first != two.first) {
            return one.first < two.first;
        }
        return two.second < one.second;
    });
#ifdef DEBUG
    printf("presents: \n");
    for (auto p : presents) {
        printf("  (%d, %d)\n", p.first, p.second);
    }
#endif

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        const int value_b = presents[i].second;
        const int id_b = value_to_id[value_b]; 
#ifdef DEBUG
        printf("+= %d\n", st->query(0, id_b + 1));
#endif
        ans += st->query(0, id_b + 1);
        st->update(id_b, st->query(id_b, id_b + 1) - 1); 
    }

    // (a, b) が同じプレゼント同士の考慮ができていないので
    ans += add_for_same_presents();

    cout << ans << endl;
    return 0;
}
