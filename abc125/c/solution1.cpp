#include <algorithm>
#include <cmath>
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

vector<int> A;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int N;
    cin >> N;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int cand1, cand2;
    {
        int cand_pos = -1;
        int prev_val = A[0];
        for (int i = 1; i < N; i++) {
            int val = gcd(A[i], prev_val);
            if (val < prev_val) {
                cand_pos = i;
            }
            prev_val = val;
            // printf("cand_pos: %d, prev_val: %d\n", cand_pos, prev_val);
        }

        cand1 = A[0];
        for (int i = 0; i < N; i++) {
            if (i == cand_pos) continue;
            cand1 = gcd(A[i], cand1);
        }
    }
    {
        int cand_pos = -1;
        int prev_val = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            int val = gcd(max(A[i], prev_val), min(A[i], prev_val));
            if (val < prev_val) {
                cand_pos = i;
            }
            prev_val = val;
            // printf("cand_pos: %d, prev_val: %d\n", cand_pos, prev_val);
        }

        cand2 = A[N - 1];
        for (int i = 0; i < N; i++) {
            if (i == cand_pos) continue;
            cand2 = gcd(A[i], cand2);
        }
    }

    cout << max(cand1, cand2) << endl;

    return 0;
}
