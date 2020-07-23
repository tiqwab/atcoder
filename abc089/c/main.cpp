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

ll solve(const int pos, vector<int> &acc, const vector<ll> &cnts) {
    if (acc.size() == 3) {
        // printf("%d, %d, %d\n", acc[0], acc[1], acc[2]);
        return cnts[acc[0]] * cnts[acc[1]] * cnts[acc[2]];
    }

    if (pos >= 5) {
        return 0LL;
    }

    ll sum = 0LL;

    for (int i = pos; i < 5; i++) {
        acc.push_back(i);
        sum += solve(i + 1, acc, cnts);
        acc.pop_back();
    }

    return sum;
}

int main(void) {
    int N;
    cin >> N;

    ll cnt_m = 0;
    ll cnt_a = 0;
    ll cnt_r = 0;
    ll cnt_c = 0;
    ll cnt_h = 0;

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        switch (name[0]) {
            case 'M':
                cnt_m++;
                break;
            case 'A':
                cnt_a++;
                break;
            case 'R':
                cnt_r++;
                break;
            case 'C':
                cnt_c++;
                break;
            case 'H':
                cnt_h++;
                break;
            default:
                break;
        }
    }

    vector<ll> cnts = {cnt_m, cnt_a, cnt_r, cnt_c, cnt_h};
    vector<int> acc;
    cout << solve(0, acc, cnts) << endl;

    return 0;
}
