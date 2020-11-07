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

vector<int> xs;
vector<int> ys;

int main(void) {
    int N;
    cin >> N;

    xs.resize(N);
    ys.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> xs[i] >> ys[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                int ix = xs[i];
                int iy = ys[i];

                int jx = xs[j];
                int jy = ys[j];
                jx -= ix;
                jy -= iy;

                int kx = xs[k];
                int ky = ys[k];
                kx -= ix;
                ky -= iy;

                if (jy * kx == jx * ky) {
                    cout << "Yes" <<endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
