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
    ll L, R;
    cin >> N >> L >> R;

    vector<ll> as;
    for (int i = 0 ; i < N; i++) {
        ll a;
        cin >> a;
        as.push_back(a);
    }

    vector<ll> acc_l(N + 1, 0);
    for (int i = 0; i < N; i++) {
        acc_l[i + 1] = acc_l[i] + L - as[i];
    }
#ifdef DEBUG
    printf("acc_l: ");
    for (int i = 0; i < N + 1; i++) {
        printf("%lld ", acc_l[i]);
    }
    printf("\n");
#endif

    vector<ll> acc_r(N + 1, 0);
    for (int i = 0; i < N; i++) {
        acc_r[i + 1] = acc_r[i] + R - as[N - i - 1];
    }
#ifdef DEBUG
    printf("acc_r: ");
    for (int i = 0; i < N + 1; i++) {
        printf("%lld ", acc_r[i]);
    }
    printf("\n");
#endif

    vector<ll>min_acc_r(N + 1, 0);
    for (int i = 0; i < N; i++) {
        min_acc_r[i + 1] = min(min_acc_r[i], acc_r[i + 1]);
    }
#ifdef DEBUG
    printf("min_acc_r: ");
    for (int i = 0; i < N + 1; i++) {
        printf("%lld ", min_acc_r[i]);
    }
    printf("\n");
#endif

    ll sum = 0;
    for (int i = 0 ; i < N; i++) {
        sum += as[i];
    }

    ll cand = sum;
    for (int i = 0; i <= N; i++) {
        chmin(cand, sum + acc_l[i] + min_acc_r[N - i]);
    }

    printf("%lld\n", cand);
    return 0;
}
