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
    int N, M;
    cin >> N >> M;

    vector<bool> correct(N, false);
    vector<int> penalty(N, 0);

    for (int i = 0; i < M; i++) {
        int p;
        string S;
        cin >> p >> S;
        p--;

        if (S == "AC") {
            if (!correct[p]) {
                correct[p] = true;
            }
        } else if (S == "WA") {
            if (!correct[p]) {
                penalty[p]++;
            }
        }
    }

    int penalty_num = 0;
    int correct_num = 0;
    for (int i = 0; i < N; i++) {
        if (correct[i]) {
            correct_num++;
            penalty_num += penalty[i];
        }
    }

    cout << correct_num << " " << penalty_num << endl;

    return 0;
}
