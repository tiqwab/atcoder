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

map<int, int> counter;
vector<ll> A;

vector<int> derive_binary(ll k, int len) {
    vector<int> binary_k;
    while (k > 0) {
        if (k % 2) {
            binary_k.push_back(1);
        } else {
            binary_k.push_back(0);
        }
        k >>= 1;
    }

    while (len > 0 && (int) binary_k.size() < len) {
        binary_k.push_back(0);
    }
    return binary_k;
}

void print_binary(vector<int> &b) {
    cout << "0b";
    for (int i = 0; i < (int) b.size(); i++) {
        cout << b[i];
    }
    cout << endl;
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    int len = 0;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        A[i] = x;

        int j = 0;
        while (x > 0) {
            if (x % 2) {
                counter[j + 1]++;
            }
            j++;
            x >>= 1;
        }
        chmax(len, j);
    }

    ll ideal = 0;
    for (int i = len; i >= 1; i--) {
        ideal <<= 1;
        if (counter[i] < (N + 1) / 2) {
            ideal += 1;
        }
    }

#ifdef DEBUG
    printf("len: %d, ideal: %lld\n", len, ideal);
#endif

    vector<int> binary_k = derive_binary(K, 0);
    vector<int> binary_i = derive_binary(ideal, len);

    if (binary_k.size() < binary_i.size()) {
        for (int i = binary_k.size(); i < (int) binary_i.size(); i++) {
            binary_k.push_back(0);
        }
    } else if (binary_k.size() > binary_i.size()) {
        for (int i = binary_i.size(); i < (int) binary_k.size(); i++) {
            binary_i.push_back(binary_k[i]);
            // binary_i.push_back(0);
        }
    }

    reverse(binary_k.begin(), binary_k.end());
    reverse(binary_i.begin(), binary_i.end());

#ifdef DEBUG
    cout << "k: ", print_binary(binary_k);
    cout << "ideal: ", print_binary(binary_i);
#endif

    int pos = 0;
    vector<int> binary_ans;
    for (; pos < (int) binary_k.size(); pos++) {
        if (binary_k[pos] > binary_i[pos]) {
            binary_ans.push_back(binary_i[pos]);
            pos++;
            break;
        } else if (binary_k[pos] < binary_i[pos]) {
            binary_ans.push_back(0);
        } else {
            binary_ans.push_back(binary_k[pos]);
        }
    }
    while (pos < (int) binary_i.size()) {
        binary_ans.push_back(binary_i[pos]);
        pos++;
    }
#ifdef DEBUG
    print_binary(binary_ans);
#endif

    ll x = 0;
    for (int i = 0; i < (int) binary_ans.size(); i++) {
        x <<= 1;
        if (binary_ans[i]) {
            x += 1;
        }
    }

#ifdef DEBUG
    printf("x: %lld\n", x);
#endif

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += x ^ A[i];
    }

    cout << ans << endl;

    return 0;
}
