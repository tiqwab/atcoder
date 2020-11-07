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

set<map<int, int>> oks;

int main(void) {
    string S;
    cin >> S;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (i != 0 && j == 0) {
                    continue;
                }

                map<int, int> s;

                s[i]++;
                s[j]++;
                s[k]++;

                int x = i * 100 + j * 10 + k * 1;

#ifdef DEBUG
                printf("%d\n", x);
                for (auto x : s) {
                    printf("%d: %d, ", x.first, x.second);
                }
                cout << endl;
#endif

                if (x % 2 == 1) {
                    continue;
                }

                x /= 2;
                x %= 100;

                if (x % 4 != 0) {
                    continue;
                }

                oks.insert(s);
            }
        }
    }

#ifdef DEBUG
    printf("oks: \n");
    for (auto xs : oks) {
        for (auto x : xs) {
            printf("%d: %d, ", x.first, x.second);
        }
        cout << endl;
    }
#endif

    map<int, int> counter;
    for (char c : S) {
        int x = c - '0';
        counter[x]++;
    }
    if ((int) S.size() == 1) {
        counter[0] = 2;
    }
    if ((int) S.size() == 2) {
        counter[0] = 1;
    }

    for (auto &ok_map : oks) {
        bool ok = true;
        for (auto ok_elem : ok_map) {
            if (counter[ok_elem.first] < ok_elem.second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
