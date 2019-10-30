#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

const int INF = 300001;

using namespace std;

int solve(vector<pair<int, int>> xs, const int k) {
    int count = 0;
    int i = 0;
    int j = 0;
    int min = INF;

    while (i + k <= ((int) xs.size())) {
        // cout << "(" << xs[i+j].first << "," << xs[i+j].second << ")" << endl;
        if (xs[i+j].second > 0) {
            if (xs[i+j].second < min) {
                min = xs[i+j].second;
            }
            j++;
            if (j == k) {
                // cout << i << "," << j << "," << min << endl;
                count += min;
                for (int m = 0; m < k; m++) {
                    xs[i+m].second -= min;
                }
                j = 0;
                min = INF;
            }
        } else {
            i++;
        }
        // cout << i << ", " << j << ", " << min << endl;
    }

    return count;
}

bool comp(const pair<int, int> x, const pair<int, int> y) {
    return x.second > y.second;
}

int main(void) {
    int n;
    cin >> n;

    map<int, int> as;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = as.find(x);
        if (it == as.end()) {
            as[x] = 1;
        } else {
            as[x] = as.at(x) + 1;
        }
    }

    vector<pair<int, int>> bs;
    for (auto p : as) {
        bs.emplace_back(p);
    }

    sort(bs.begin(), bs.end(), comp);

    for (int i = 1; i <= n; i++) {
        cout << solve(bs, i) << endl;
    }

    return 0;
}
