#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

    if ((int) S.size() == 1) {
        if (S == "8") {
            cout << "Yes" << endl;
            return 0;
        }
    } else if ((int) S.size() == 2) {
        int a = S[1] - '0';
        int b = S[0] - '0';
        if (((a * 10 + b) % 8 == 0) || ((b * 10 + a) % 8 == 0)) {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        map<char, int> s_counter;
        for (auto c : S) {
            s_counter[c]++;
        }

        for (int i = 112; i < 1000; i += 8) {
            string eight_mul = to_string(i);
            map<char, int> eight_mul_counter;
            for (auto c : eight_mul) {
                eight_mul_counter[c]++;
            }

            bool ok = true;
            for (auto p : eight_mul_counter) {
                if (s_counter[p.first] < p.second) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
