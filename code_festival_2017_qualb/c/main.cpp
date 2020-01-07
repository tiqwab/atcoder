#include <algorithm>
#include <cassert>
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

vector<vector<int>> edges;
vector<int> colors; // 0: unassigned, 1: black, 2: white, 3: both

void assign_colors(const int cur, const int col, const int N, const int M) {
    if (colors[cur] & col) {
        return;
    }

    colors[cur] |= col;

    for (auto next_v : edges[cur]) {
        int next_col = 3 - col;
        assign_colors(next_v, next_col, N, M);
    }
}

int main(void) {
    int N, M;
    cin >> N >> M;

    edges.resize(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }

    colors.resize(N, 0);
    assign_colors(0, 1, N, M);

    int black_count = 0, white_count = 0;
    bool both_color_exists = false;
    for (int i = 0; i < N; i++) {
        assert(colors[i] != 0);
        if (colors[i] == 1) black_count++;
        else if (colors[i] == 2) white_count++;
        else if (colors[i] == 3) both_color_exists = true;
    }

    ll ans = 0;
    if (both_color_exists) {
        ans = ((ll) N) * ((ll) (N - 1)) / 2 - ((ll) M);
    } else {
        for (int i = 0; i < N; i++) {
            if (colors[i] == 1) {
                ans += white_count - ((int) edges[i].size());
            } else if (colors[i] == 2) {
                ans += black_count - ((int) edges[i].size());
            }
        }
        assert(ans % 2 == 0);
        ans /= 2;
    }

    cout << ans << endl;

    return 0;
}
