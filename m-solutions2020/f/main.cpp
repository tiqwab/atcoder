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

const int INF = INT_MAX / 2;

// {x, y}
vector<pair<int, int>> us;
vector<pair<int, int>> ds;
vector<pair<int, int>> rs;
vector<pair<int, int>> ls;

vector<pair<int, int>> rotate90(const vector<pair<int, int>> &vs) {
    vector<pair<int, int>> res(vs.size());
    for (int i = 0; i < (int) vs.size(); i++) {
        res[i] = make_pair(-1 * vs[i].second, vs[i].first);
    }
    return res;
}

vector<pair<int, int>> rotate180(const vector<pair<int, int>> &vs) {
    vector<pair<int, int>> res(vs.size());
    for (int i = 0; i < (int) vs.size(); i++) {
        res[i] = make_pair(-1 * vs[i].first, -1 * vs[i].second);
    }
    return res;
}

vector<pair<int, int>> rotate270(const vector<pair<int, int>> &vs) {
    vector<pair<int, int>> res(vs.size());
    for (int i = 0; i < (int) vs.size(); i++) {
        res[i] = make_pair(vs[i].second, -1 * vs[i].first);
    }
    return res;
}

int calc_for_ud(const vector<pair<int, int>> &us, const vector<pair<int, int>> &ds) {
    // map x to {y, dir}
    // dir = -1 for up, 1 for down
    map<int, vector<pair<int, int>>> ms;
    for (auto u : us) {
        ms[u.first].push_back(make_pair(u.second, -1));
    }
    for (auto d : ds) {
        ms[d.first].push_back(make_pair(d.second, 1));
    }

    int ans = INF;
    for (auto &m : ms) {
        auto &vs = m.second;
        sort(vs.begin(), vs.end());
        for (int i = 0; i < (int) vs.size() - 1; i++) {
            if (vs[i].second == -1 && vs[i + 1].second == 1) {
                chmin(ans, (vs[i + 1].first - vs[i].first) * 5);
            }
        }
    }
    return ans;
}

int calc_for_ur(const vector<pair<int, int>> &us, const vector<pair<int, int>> &rs) {
    // map (x + y) to {y, dir}
    // dir = -1 for up, 1 for down
    map<int, vector<pair<int, int>>> ms;
    for (auto u : us) {
        ms[u.first + u.second].push_back(make_pair(u.second, -1));
    }
    for (auto r : rs) {
        ms[r.first + r.second].push_back(make_pair(r.second, 1));
    }

    int ans = INF;
    for (auto &m : ms) {
        auto &vs = m.second;
        sort(vs.begin(), vs.end());
        for (int i = 0; i < (int) vs.size() - 1; i++) {
            if (vs[i].second == -1 && vs[i + 1].second == 1) {
                chmin(ans, (vs[i + 1].first - vs[i].first) * 10);
            }
        }
    }
    return ans;
}

int solve(const int N) {
    int ans = INF;

    // U and D
    {
        chmin(ans, calc_for_ud(us, ds));
    }

    // L and R
    {
        vector<pair<int, int>> rotated_rs = rotate90(rs);
        vector<pair<int, int>> rotated_ls = rotate90(ls);
        chmin(ans, calc_for_ud(rotated_rs, rotated_ls));
    }

    // U and R
    {
        chmin(ans, calc_for_ur(us, rs));
    }

    // R and D
    {
        vector<pair<int, int>> rotated_rs = rotate90(rs);
        vector<pair<int, int>> rotated_ds = rotate90(ds);
        chmin(ans, calc_for_ur(rotated_rs, rotated_ds));
    }

    // D and L
    {
        vector<pair<int, int>> rotated_ds = rotate180(ds);
        vector<pair<int, int>> rotated_ls = rotate180(ls);
        chmin(ans, calc_for_ur(rotated_ds, rotated_ls));
    }

    // L and U
    {
        vector<pair<int, int>> rotated_ls = rotate270(ls);
        vector<pair<int, int>> rotated_us = rotate270(us);
        chmin(ans, calc_for_ur(rotated_ls, rotated_us));
    }

    return ans;
}

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        switch (dir) {
            case 'U':
                us.push_back(make_pair(x, y));
                break;
            case 'D':
                ds.push_back(make_pair(x, y));
                break;
            case 'R':
                rs.push_back(make_pair(x, y));
                break;
            case 'L':
                ls.push_back(make_pair(x, y));
                break;
            default:
                break;
        }
    }

    int ans = solve(N);
    if (ans == INF) {
        cout << "SAFE" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
