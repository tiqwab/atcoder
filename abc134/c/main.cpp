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
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B.begin(), B.end());
    int fst = B[N - 1];
    int snd = B[N - 2];

    for (int i = 0; i < N; i++) {
        if (A[i] == fst) {
            cout << snd << endl;
        } else {
            cout << fst << endl;
        }
    }
    
    return 0;
}
