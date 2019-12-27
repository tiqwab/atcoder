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

int solve(const int n, const vector<int> &p) {
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
                (p[i + 1] < p[i] && p[i] < p[i - 1])) {
            count++;
        }
    }

    return count;
}

int main(void) {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solve(n, p) << endl;
    
    return 0;
}
