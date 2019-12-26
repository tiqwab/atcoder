#include <algorithm>
#include <iostream>
#include <vector>

#include <math.h>

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

ll calc_dist_two(const int D, vector<ll> a, vector<ll> b) {
    ll res = 0;
    for (int i = 0; i < D; i++) {
        res += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return res;
}

int main(void) {
    int N, D;
    cin >> N >> D;

    vector<vector<ll> > points(N, vector<ll>(D));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> points[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ll dist = calc_dist_two(D, points[i], points[j]);
            for (ll k = 1; k <= dist; k++) {
                if ((k * k) == dist) {
                    count++;
                    break;
                } else if ((k * k) > dist) {
                    break;
                }
            }
        }
    }

    cout << count << endl;
    
    return 0;
}
