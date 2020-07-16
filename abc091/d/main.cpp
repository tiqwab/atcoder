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

int f(const int target, const int a, const int N, const vector<int> &ns) {
    int left = -1, right = N, mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        int b = ns[mid];
#ifdef DEBUG
        printf("left: %d, right: %d, mid: %d, a: %d, b: %d\n", left, right, mid, a, b);
#endif
        if (a + b < target) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    vector<int> ans_bits;
    vector<int> bs2(N);

    // why failed if bit < 28 -> a + b might have bit 28 (e.g. a = (1 << 28) - 1, b = (1 << 28) - 1.
    for (int bit = 0; bit < 29; bit++) {
        for (int i = 0; i < N; i++) {
            bs2[i] = bs[i] % (1 << (bit + 1));
        }
        sort(bs2.begin(), bs2.end());

        ll cnt = 0;
        for (auto orig_a : as) {
            int a = orig_a % (1 << (bit + 1));
            int T = 1 << bit;
            {
#ifdef DEBUG
                printf("[%d, %d): \n", (1 << bit), 2 * (1 << bit));
#endif
                int left = f(T, a, N, bs2);
                int right = f(2 * T, a, N, bs2);
#ifdef DEBUG
                printf("bit: %d, a: %d, left: %d, right: %d\n", bit, a, left, right);
#endif
                cnt += right - left;
            }
            {
#ifdef DEBUG
                printf("[%d, %d): \n", 3 * (1 << bit), 4 * (1 << bit));
#endif
                int left = f(3 * T, a, N, bs2);
                int right = N;
                // int right = f(bit, 4 * (1 << bit), a, N, bs2);
#ifdef DEBUG
                printf("bit: %d, a: %d, left: %d, right: %d\n", bit, a, left, right);
#endif
                cnt += right - left;
            }
        }
        if (cnt % 2 == 0) {
            ans_bits.push_back(0);
        } else {
            ans_bits.push_back(1);
        }
    }


    reverse(ans_bits.begin(), ans_bits.end());
    ll ans = 0;
    for (auto bit : ans_bits) {
        ans = ans * 2 + bit;
    }
    cout << ans << endl;

    return 0;
}
