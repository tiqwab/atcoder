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

    if (N == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<int> binary;
    while (N != 0) {
        if (N % (-2)) {
            binary.push_back(1);
            N--;
        } else {
            binary.push_back(0);
        }
        N /= -2;
    }

    reverse(binary.begin(), binary.end());

    for (auto &b : binary) {
        cout << b;
    }
    cout << endl;

    return 0;
}
