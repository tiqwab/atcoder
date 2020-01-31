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

vector<vector<int>> obs_row;
vector<vector<int>> obs_col;
vector<string> grid;

int solve(const int H, const int W) {
    int maximum = 0;
    for (int h = 1; h <= H; h++) {
        for (int w = 1; w <= W; w++) {
            if (grid[h - 1][w - 1] == '#') continue;

            auto row = obs_row[h];
            auto col = obs_col[w];

            int left = *(upper_bound(row.begin(), row.end(), w) - 1); // the position of the nearest obstracle in left
            int right = *(lower_bound(row.begin(), row.end(), w)); // in right
            int up = *(upper_bound(col.begin(), col.end(), h) - 1); // in up
            int down = *(lower_bound(col.begin(), col.end(), h)); // in down
            // printf("(%d, %d) left: %d, right: %d, up: %d, down: %d\n", w, h, left, right, up, down);

            int res = (right - left - 1) + (down - up - 1) - 1;
            chmax(maximum, res);
        }
    }

    return maximum;
}

int main(void) {
    int H, W;
    cin >> H >> W;

    grid.resize(H);
    obs_row.resize(H + 1);
    obs_col.resize(W + 1);
    for (int i = 1; i <= W; i++) {
        obs_col[i].push_back(0);
    }
    for (int i = 1; i <= H; i++) {
        string S;
        cin >> S;
        grid[i - 1] = S;
        obs_row[i].push_back(0);
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '#') {
                obs_row[i].push_back(j);
                obs_col[j].push_back(i);
            }
        }
        obs_row[i].push_back(W + 1);
    }
    for (int i = 1; i <= W; i++) {
        obs_col[i].push_back(H + 1);
    }

    // cout << "obs_row: " << endl;
    // for (int i = 0; i < (int) obs_row.size(); i++) {
    //     for (int j = 0; j < (int) obs_row[i].size(); j++) {
    //         cout << obs_row[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // cout << "obs_col: " << endl;
    // for (int i = 0; i < (int) obs_col.size(); i++) {
    //     for (int j = 0; j < (int) obs_col[i].size(); j++) {
    //         cout << obs_col[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << solve(H, W) << endl;

    return 0;
}
