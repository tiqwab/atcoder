#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

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
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        A[i] = v;
    }

    deque<int> q;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(q.begin(), q.end(), A[i]);
        if (it == q.begin()) {
            q.push_front(A[i]);
        } else {
            q[it - q.begin() - 1] = A[i];
        }
    }

    cout << q.size() << endl;

    return 0;
}
