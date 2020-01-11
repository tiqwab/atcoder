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

ll comb2(const ll a) {
    return a * (a - 1) / 2;
}

vector<vector<ll>> edges;

int main(void) {
    ll N, K;
    cin >> N >> K;

    ll max_num = (N - 2) + comb2(N - 2);
    if (K > max_num) {
        cout << "-1" << endl;
        return 0;
    }

    edges.resize(N);
    edges[0].push_back(1);
    for (int i = 2; i < N; i++) {
        edges[1].push_back(i);
    }

    ll remain = max_num - K;
    // printf("max_num: %lld, remain: %lld\n", max_num, remain);
    ll link_one_num = min(remain, N - 2);
    for (int i = 0; i < link_one_num; i++) {
        edges[0].push_back(i + 2);
    }
    remain = remain - link_one_num;

    int i = 2;
    while (remain > 0) {
        for (int j = i + 1; j < N; j++) {
            edges[i].push_back(j);
            remain--;
            if (remain == 0) break;
        }
        i++;
    }

    ll count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int) edges[i].size(); j++) {
            count++;
        }
    }
    cout << count << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int) edges[i].size(); j++) {
            cout << i + 1 << " " << edges[i][j] + 1 << endl;
        }
    }

    return 0;
}
