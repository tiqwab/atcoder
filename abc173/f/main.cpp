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
    ll N;
    cin >> N;

    ll n_sub = 0;
    for (int i = 0; i < N - 1; i++) {
        ll u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        n_sub += u * (N - v + 1);
    }

    ll n_vertices = 0;
    for (ll i = 1; i <= N; i++) {
        n_vertices += i * (N - i + 1);
    }

    // printf("n_vertices: %lld, n_sub: %lld, ans: %lld\n", n_vertices, n_sub, n_vertices - n_sub);
    cout << n_vertices - n_sub << endl;

    return 0;
}
