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

int counter[4];

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "AC") {
            counter[0]++;
        } else if (s == "WA") {
            counter[1]++;
        } else if (s == "TLE") {
            counter[2]++;
        } else if (s == "RE") {
            counter[3]++;
        }
    }

    printf("AC x %d\n", counter[0]);
    printf("WA x %d\n", counter[1]);
    printf("TLE x %d\n", counter[2]);
    printf("RE x %d\n", counter[3]);
    return 0;
}
