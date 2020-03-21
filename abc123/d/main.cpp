#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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

vector<ll> A;
vector<ll> B;
vector<ll> C;

vector<ll> ans;
set<tuple<int, int, int>> exists;

void solve(const ll K) {
    int num = 0;

    priority_queue<tuple<ll, int, int, int>> q; // {value, ind_a, ind_b, ind_c}
    q.push(make_tuple(A[0] + B[0] + C[0], 0, 0, 0));
    exists.insert(make_tuple(0, 0, 0));

    while (num < K) {
        assert(!q.empty());
        ll v;
        int a, b, c;

        tie(v, a, b, c) = q.top();
        // printf("%lld, %d, %d, %d\n", v, a, b, c);
        q.pop();
        ans.push_back(v);
        num++;

        if (a < (int) A.size() - 1) {
            a++;
            if (exists.find(make_tuple(a, b, c)) == exists.end()) {
                v = A[a] + B[b] + C[c];
                tuple<ll, int, int, int> tup(v, a, b, c);
                q.push(tup);
                exists.insert(make_tuple(a, b, c));
            }
            a--;
        }
        if (b < (int) B.size() - 1) {
            b++;
            if (exists.find(make_tuple(a, b, c)) == exists.end()) {
                v = A[a] + B[b] + C[c];
                tuple<ll, int, int, int> tup(v, a, b, c);
                q.push(tup);
                exists.insert(make_tuple(a, b, c));
            }
            b--;
        }
        if (c < (int) C.size() - 1) {
            c++;
            if (exists.find(make_tuple(a, b, c)) == exists.end()) {
                v = A[a] + B[b] + C[c];
                tuple<ll, int, int, int> tup(v, a, b, c);
                q.push(tup);
                exists.insert(make_tuple(a, b, c));
            }
            c--;
        }
    }
}

int main(void) {
    int X, Y, Z;
    ll K;
    cin >> X >> Y >> Z >> K;

    A.resize(X);
    for (int i = 0; i < X; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    B.resize(Y);
    for (int i = 0; i < Y; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    C.resize(Z);
    for (int i = 0; i < Z; i++) {
        cin >> C[i];
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());

    solve(K);

    for (int i = 0; i < K; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
