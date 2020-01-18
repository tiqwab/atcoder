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

int main(void) {
    ll N;
    cin >> N;

    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<ll> C(N);
    ll minus_sum = 0;
    int minus_count = 0;
    for (int i = 0; i < N; i++) {
        C[i] = A[i] - B[i];
        if (C[i] < 0) {
            minus_sum += C[i];
            minus_count++;
        }
    }

    if (minus_sum == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<ll> pluses;
    for (int i = 0; i < N; i++) {
        if (C[i] > 0) {
            pluses.push_back(C[i]);
        }
    }
    // sort by descending order
    sort(pluses.begin(), pluses.end(), [](const ll &a, const ll &b) {
            return a > b;
            });

    int plus_count = 0;
    for (int i = 0; i < (int) pluses.size(); i++) {
        minus_sum += pluses[i];
        plus_count++;
        if (minus_sum >= 0) break;
    }

    if (minus_sum < 0) {
        cout << "-1" << endl;
    } else {
        cout << minus_count + plus_count << endl;
    }

    return 0;
}
