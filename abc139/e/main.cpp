#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

#define DEP_SIZE(n) (n * n)

const int MAX_N = 1000;
const int MAX_DEP_SIZE = MAX_N * MAX_N;

vector<int> edges[MAX_N];
vector<int> dependencies[MAX_DEP_SIZE];
int memo[MAX_DEP_SIZE];
bool visited[MAX_DEP_SIZE];
int n;

int solve(int match, int count) {
    if (memo[match] != 0) {
        // cout << "from memo[" << match << "]: " << memo[match] << endl;
        return memo[match];
    }
    if (visited[match]) {
        return -1;
    }

    visited[match] = true;

    vector<int> depends = dependencies[match];

    int max = count;
    for (int i = 0; i < (int) depends.size(); i++) {
        int res = solve(depends[i], 1);
        if (res < 0) {
            return -1;
        } else if (res + count > max) {
            max = res + count;
        }
    }

    memo[match] = max;
    // cout << "memo[" << match << "]: " << memo[match] << endl;

    return max;
}

#define MATCH(p1, p2, n) (((p1) - 1) * (n) + ((p2) - 1))

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int x;
            cin >> x;
            edges[i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++) {
        int prev_match = -1;
        for (int j = 0; j < n - 1; j++) {
            int p1 = i + 1;
            int p2 = edges[i][j];

            int cur_match = MATCH(p1, p2, n);

            if (prev_match >= 0) {
                dependencies[cur_match].push_back(prev_match);
            }

            // search from opposite edges
            int k;
            for (k = n - 1; k >= 0; k--) {
                if (edges[p2 - 1][k] == p1) {
                    break;
                }
            }
            if (k > 0) {
                int match = MATCH(p2, edges[p2 - 1][k - 1], n);
                dependencies[cur_match].push_back(match);
            }

            prev_match = cur_match;
        }
    }

    // to debug dependencies
    // for (int i = 0; i < DEP_SIZE(n); i++) {
    //     cout << "dependency for " << i << ": ";
    //     for (int j = 0; j < (int) dependencies[i].size(); j++) {
    //         cout << dependencies[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 0; i < DEP_SIZE(n); i++) {
        int res = solve(i, 1);
        if (res < 0) {
            ans = -1;
            break;
        } else if (res > ans) {
            ans = res;
        }
    }

    cout << ans << endl;
    
    return 0;
}
