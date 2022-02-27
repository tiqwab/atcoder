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

vector<int> students;

int solve(const int border) {
    int n = (int) students.size();
    int left = 0, right = n;

    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (students[mid] < border) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return n - (left + 1);
}

int main(void) {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        students.push_back(x);
    }
    students.push_back(0);
    sort(students.begin(), students.end());

    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        printf("%d\n", solve(x));
    }

    return 0;
}
