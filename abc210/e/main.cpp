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

int gcd(int a, int b) {
    if (a > b) {
        return gcd(b, a);
    }
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// {cost, Ai}
vector<pair<ll, int>> actions;

int main(void) {
    int N, M;
    cin >> N >> M;

    actions.resize(M);
    for (int i = 0; i < M; i++) {
        int a;
        ll c;
        cin >> a >> c;
        actions[i] = make_pair(c, a);
    }
    sort(actions.begin(), actions.end());

    int g = N;
    ll acc = 0;

    // we can assume that g (the number of nodes) changes to gcd(g, a) by each action
    // (n nodes can be grouped by gcd(n, a), and then we don't have to think of nodes larger than n)
    for (auto action : actions) {
        const int a = action.second;
        const ll cost = action.first;
        int new_g = gcd(g, a);
        acc += cost * (g - new_g);
        g = new_g;
    }

    if (g != 1) {
        cout << -1 << endl;
    } else {
        cout << acc << endl;
    }

    return 0;
}
