#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

template<class t>
inline bool chmax(t &a, t b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class t>
inline bool chmin(t &a, t b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

// {delicious, kind}
vector<pair<ll, int>> sushi;
// {kind, count}
map<int, int> counter;

ll solve(const int n, const int k) {
    ll cand = 0;
    ll delicious = 0;
    ll kinds = 0;
    vector<ll> replacables;

    for (int i = 0; i < k; i++) {
        pair<ll, int> su = sushi[i];
        counter[su.second]++;
        delicious += su.first;
        if (counter[su.second] == 1) {
            kinds++;
        } else {
            replacables.push_back(su.first);
        }
    }

    cand = delicious + kinds * kinds;
    // printf("cand: %lld\n", cand);

    for (int i = k; i < n; i++) {
        if ((int) replacables.size() == 0) {
            break;
        }
        pair<ll, int> su = sushi[i];
        if (counter[su.second] > 0) continue;
        counter[su.second]++;
        ll replace = replacables.back();
        replacables.pop_back();
        delicious -= replace;
        delicious += su.first;
        kinds++;
        chmax(cand, delicious + kinds * kinds);

    }

    return cand;
}

int main(void) {
    int n, k;
    cin >> n >> k;

    sushi.resize(n);
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        sushi[i] = {d, t};
    }
    sort(sushi.begin(), sushi.end());
    reverse(sushi.begin(), sushi.end());

    cout << solve(n, k) << endl;

    return 0;
}
