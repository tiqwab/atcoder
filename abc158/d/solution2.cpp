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
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    int direction = 1;
    vector<char> A, B;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            direction *= -1;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (direction == 1) {
                    A.push_back(c);
                } else {
                    B.push_back(c);
                }
            } else {
                if (direction == 1) {
                    B.push_back(c);
                } else {
                    A.push_back(c);
                }
            }
        }
    }

    if (direction == 1) {
        reverse(A.begin(), A.end());
        string s1 = string(A.begin(), A.end());
        string s2 = string(B.begin(), B.end());
        cout << s1 << S << s2 << endl;
    } else {
        reverse(B.begin(), B.end());
        reverse(S.begin(), S.end());
        string s1 = string(B.begin(), B.end());
        string s2 = string(A.begin(), A.end());
        cout << s1 << S << s2 << endl;
    }

    return 0;
}
