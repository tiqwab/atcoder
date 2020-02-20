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

vector<int> A;

// {C, B}
vector<pair<int, int>> cands;

ll solve(const int N, const int M) {
    int c_i = 0;

    for (int a_i = 0; a_i < N; a_i++) {
        int a = A[a_i];

        if (a >= cands[c_i].first) {
            break;
        }
        A[a_i] = cands[c_i].first;

        cands[c_i].second--;
        if (cands[c_i].second == 0) {
            c_i++;
        }
        if (c_i >= M) {
            break;
        }
        // printf("a_i: %d, c_i: %d\n", a_i, c_i);
    }

    ll acc = 0;
    for (int i = 0; i < N; i++) {
        acc += A[i];
    }
    return acc;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cands.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> cands[i].second >> cands[i].first;
    }

    // sort by descending order of C
    sort(cands.begin(), cands.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
            });

    // for (int i = 0; i < M; i++) {
    //     printf("{%d, %d}\n", cands[i].first, cands[i].second);
    // }

    cout << solve(N, M) << endl;

    return 0;
}
