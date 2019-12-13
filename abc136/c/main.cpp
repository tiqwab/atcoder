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

bool solve(const vector<int> &H) {
    int h = H[0];
    bool ok = true;
    for (int i = 1; i < (int) H.size(); i++) {
        if (h > H[i]) {
            ok = false;
            break;
        } else if (h == H[i]) {
            ;
        } else {
            h = H[i] - 1;
        }
    }
    return ok;
}

int main(void) {
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    if (solve(H)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
