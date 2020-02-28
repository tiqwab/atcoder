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

int pow(const int base, int m) {
    int res = 1;
    while (m > 0) {
        res *= base;
        m--;
    }
    return res;
}

int main(void) {
    int M, K;
    cin >> M >> K;

    if (K >= pow(2, M)) {
        cout << "-1" << endl;
        return 0;
    } else if (M == 0) {
        if (K == 0) {
            cout << "0 0" << endl;
        } else {
            cout << "-1" << endl;
        }
        return 0;
    } else if (M == 1) {
        if (K == 0) {
            cout << "0 0 1 1" << endl;
        } else {
            cout << "-1" << endl;
        }
        return 0;
    }

    vector<int> ans(pow(2, M + 1), 0);
    ans[0] = K;
    ans[pow(2, M)] = K;

    int v = 0;
    for (int i = 1; i < pow(2, M); i++) {
        if (v == K) v++;
        ans[i] = v;
        ans[((int) ans.size()) - i] = v;
        v++;
    }

    cout << ans[0];
    for (int i = 1; i < (int) ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
