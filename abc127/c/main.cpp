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

// {pos, a}, a == 0 for L, a == 1 for R 
vector<pair<int, int>> events;

int solve(const int N, const int M) {
    int ans = 0;
    int pos = 1;
    int i_e = 0;
    int acc = 0;

    while (pos <= N) {
        while (i_e < 2 * M && events[i_e].first == pos) {
            if (events[i_e].second == 0) {
                acc++;
            } else {
                acc--;
            }
            i_e++;
        }
        if (acc == M) {
            ans++;
        }
        // printf("pos: %d, i_e: %d, acc: %d, ans: %d\n", pos, i_e, acc, ans);
        pos++;
    }

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        events.push_back({L, 0});
        events.push_back({R + 1, 1});
    }
    sort(events.begin(), events.end());

    cout << solve(N, M) << endl;

    return 0;
}
