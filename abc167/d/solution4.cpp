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

vector<int> to;
vector<int> linear_towns;
int loop_start;
vector<int> loop_towns;

void find_loop_start() {
    int crashed;
    {
        int slow = 0;
        int fast = 0;
        int turn = 0;
        while (turn == 0 || slow != fast) {
            slow = to[slow];
            fast = to[to[fast]];
            turn++;
        }
        crashed = slow;
    }

    int one = 0;
    int other = crashed;
    linear_towns.push_back(0);
    while (one != other) {
        one = to[one];
        other = to[other];
        linear_towns.push_back(one);
    }
    loop_start = one;
}

void find_loop_towns(int cur, const int start) {
    if (!loop_towns.empty() && cur == start) {
        return;
    }
    loop_towns.push_back(cur);
    return find_loop_towns(to[cur], start);
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    to.resize(N, 0);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        t--;
        to[i] = t;
    }

    find_loop_start();
    
    if (K <= (ll) linear_towns.size() - 1) {
        cout << linear_towns[K] + 1 << endl;
        return 0;
    }

    K -= (ll) linear_towns.size() - 1;
    find_loop_towns(loop_start, loop_start);

    cout << loop_towns[K % (ll) loop_towns.size()] + 1 << endl;
    return 0;
}
