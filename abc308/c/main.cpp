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
    int N;
    cin >> N;

    vector<tuple<ll, ll, int>> people;
    for (int i = 0; i < N; i++) {
        ll a;
        ll b;
        cin >> a >> b;
        people.push_back(make_tuple(a, b, i));
    }

    // 最終的に成功率が同じ場合に番号の昇順に出すため
    reverse(people.begin(), people.end());

    stable_sort(people.begin(), people.end(), [](const tuple<ll, ll, int>& lhs, const tuple<ll, ll, int>& rhs) {
        ll la, lb;
        int li;
        ll ra, rb;
        int ri;
        tie(la, lb, li) = lhs;
        tie(ra, rb, ri) = rhs;

        ll ln = la;
        ll ld = la + lb;
        ll rn = ra;
        ll rd = ra + rb;
        ln = ln * rd;
        rn = rn * ld;
        return ln < rn;
    });

    // 成功率が高い順にする
    reverse(people.begin(), people.end());

    for (int i = 0; i < N; i++) {
        tuple<ll, ll, int> p = people[i];
        ll la, lb;
        int li;
        tie(la, lb, li) = p;
        printf("%d ", li + 1);
    }
    printf("\n");

    return 0;
}
