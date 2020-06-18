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

vector<int> as;
int ns[1000001];

vector<int> calc_divs(int n) {
    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i * i != n) {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        ns[as[i]]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<int> ds = calc_divs(as[i]);

        // cout << "divs: " << endl;
        // for (auto d : ds) {
        //     cout << d << " ";
        // }
        // cout << endl;

        bool ok = true;
        for (auto d : ds) {
            if (ns[d] > 0) {
                if (ns[d] > 1 || d != as[i]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
