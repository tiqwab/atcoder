#include <iostream>
#include <vector>
#include <set>

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

#define LIST_SIZE(n) (n * n)

const int MAX_N = 1000;
const int MAX_LIST_SIZE = MAX_N * MAX_N;

int list[MAX_LIST_SIZE]; // 3 means 1 vs 4 if there are four players
int n;

int solve(int p1, int p2, int count, set<int> &visited) {
    int depend_match = (p1 - 1) * n + (p2 - 1);
    if (visited.find(depend_match) != visited.end()) {
        return -1;
    }
    visited.insert(depend_match);

    if (list[depend_match] == 0) {
        return count;
    }

    int new_p1 = list[depend_match] / n + 1;
    int new_p2 = list[depend_match] % n + 1;

    return solve(new_p1, new_p2, count + 1, visited);
}

int main(void) {
    cin >> n;

    // TODO: there are more dependencies
    for (int i = 0; i < n; i++) {
        int x;
        int prev_match;
        int cur_match;

        cin >> x;
        prev_match = i * n + (x - 1);

        for(int j = 0; j < n - 2; j++) {
            cin >> x;
            cur_match = i * n + (x - 1);
            list[cur_match] = prev_match;
            prev_match = cur_match;
        }
    }

    set<int> s;
    int ans = 0;
    for (int i = 0; i < LIST_SIZE(n); i++) {
        s.clear();
        int res = solve(i / n + 1, i % n + 1, 1, s);
        if (res < 0) {
            ans = -1;
            break;
        } else if (res > ans) {
            ans = res;
        }
    }

    cout << ans << endl;

    // for (int i = 0; i < LIST_SIZE(n); i++) {
    //     int p1 = i / n + 1;
    //     int p2 = i % n + 1;
    //     cout << p1 << " vs " << p2 << ": ";
    //     for (int j = 0; j < (int) list[i].size(); j++) {
    //         cout << list[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}
