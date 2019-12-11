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

static int counter(int i) {
    int count = 0;
    while (i > 0) {
        if (i & 1) {
            count++;
        }
        i = i >> 1;
    }
    return count; }

int solve(const int N, const vector<vector<pair<int, int> > > &A) {
    int max = 0;

    for (int bits = 0; bits < 1 << N; bits++) {
        bool b = true;
        for (int i = 0; i < N; i++) {
            if ((bits >> i) & 1) {
                for (int j = 0; j < (int) A[i].size(); j++) {
                    if ((((bits >> A[i][j].first) & 1) && !A[i][j].second)
                            || (!((bits >> A[i][j].first) & 1) && A[i][j].second)) {
                        b = false;
                        goto end;
                    }
                }
            }
        }
end:
        if (b) {
            chmax(max, counter(bits));
        }
    }

    return max;
}

int main(void) {
    int N;
    cin >> N;

    vector<vector<pair<int, int> > > A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            A[i].push_back({x - 1, y});
        }
    }

    cout << solve(N, A) << endl;

    return 0;
}
