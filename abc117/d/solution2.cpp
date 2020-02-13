#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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

vector<ll> A;

vector<ll> dp1;
vector<ll> dp2;
int bit_len;

vector<int> convert_binary(ll k) {
    vector<int> ans;
    while (k > 0) {
        ans.push_back(k & 0x1);
        k >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int op(const int bit, const int idx) {
    int ans = 0;
    for (int i = 1; i < (int) A.size(); i++) {
        ll x = A[i];
        ans += bit ^ ((x >> (bit_len - idx)) & 0x1);
    }
#ifdef DEBUG
    printf("bit: %d, idx: %d, ans: %d\n", bit, idx, ans);
#endif
    return ans;
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        A[i] = x;
    }

    vector<int> binary_k = convert_binary(K);
    bit_len = (int) binary_k.size();
#ifdef DEBUG
    printf("bit_len: %d\n", bit_len);
#endif

    dp1.resize(bit_len + 1, -1);
    dp2.resize(bit_len + 1, -1);
    dp1[0] = 0;

    for (int i = 0; i < bit_len; i++) {
        int d = binary_k[i];

        // dp1
        if (dp1[i] != -1) {
            chmax(dp1[i + 1], op(d, i + 1) + (dp1[i] << 1));
            if (d == 1) chmax(dp2[i + 1], op(0, i + 1) + (dp1[i] << 1));
        }

        // dp2
        if (dp2[i] != -1) {
            chmax(dp2[i + 1], op(0, i + 1) + (dp2[i] << 1));
            chmax(dp2[i + 1], op(1, i + 1) + (dp2[i] << 1));
        }
    }

#ifdef DEBUG
    printf("dp1: \n");
    for (int i = 0; i <= bit_len; i++) {
        cout << dp1[i] << " ";
    }
    cout << endl;

    printf("dp2: \n");
    for (int i = 0; i <= bit_len; i++) {
        cout << dp2[i] << " ";
    }
    cout << endl;
#endif

    ll ans = max(dp1[bit_len], dp2[bit_len]);
    for (int i = 1; i <= N; i++) {
        ans += A[i] & ~(((1LL << bit_len) - 1));
    }

    cout << ans << endl;

    return 0;
}
