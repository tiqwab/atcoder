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

vector<int> as;

int main(void) {
    int N, M;
    cin >> N >> M;

    int sum = 0;
    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        sum += as[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (as[i] * 4 * M >= sum) {
            count++;
        }
    }

    if (count >= M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
