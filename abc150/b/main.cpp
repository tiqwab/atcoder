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

    string S;
    cin >> S;

    int count = 0;
    for (int i = 0; i < N - 2; i++) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
