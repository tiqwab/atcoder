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
vector<int> bs;

map<int, int> cnt_a;
map<int, int> cnt_b;

// ref. YouTube
int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        cnt_a[as[i]]++;
    }
    sort(as.begin(), as.end());

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
        cnt_b[bs[i]]++;
    }
    sort(bs.rbegin(), bs.rend());

    int start = N;
    for (int i = 0; i < N; i++) {
        if (as[i] == bs[i]) {
            start = i;
            break;
        }
    }

    int end = N;
    for (int i = start; i < N; i++) {
        if (as[i] != bs[i]) {
            end = i;
            break;
        }
    }

    if (end - start > 0) {
        if (cnt_a[as[start]] + cnt_b[bs[start]] > N) {
            cout << "No" << endl;
            return 0;
        }

        int pos = 0;
        for (int i = start; i < end; i++) {
            while (pos >= start && pos < end) {
                pos++;
            }
            while (bs[pos] == as[i] || as[pos] == bs[i]) {
                pos++;
            }
            if (pos >= N) {
                fprintf(stderr, "illegal pos: %d\n", pos);
                return 1;
            }
            swap(bs[pos], bs[i]);
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << bs[i] << " ";
    }
    cout << endl;

    return 0;
}
