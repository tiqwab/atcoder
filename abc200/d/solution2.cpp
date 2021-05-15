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

// memo[i] is a sequences represented by bits and its sum % 200 = i.
vector<int> memo;

void show_vec(const vector<int> &xs) {
    printf("%d", (int) xs.size());
    for (int i = 0; i < (int) xs.size(); i++) {
        printf(" %d", xs[i]);
    }
    printf("\n");
}

vector<int> bits_to_vec(const int bits, const int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (bits & (1 << i)) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
    }

    const int n = min(N, 8);

    memo.resize(200, 0);

    for (int bits = 1; bits < (1 << n); bits++) {
        int rem = 0;

        for (int i = 0; i < n; i++) {
            if (bits & (1 << i)) {
                rem = (rem + as[i]) % 200;
            }
        }

        if (memo[rem] != 0) {
            printf("Yes\n");
            show_vec(bits_to_vec(bits, n));
            show_vec(bits_to_vec(memo[rem], n));
            return 0;
        }

        memo[rem] = bits;
    }

    printf("No\n");
    return 0;
}
