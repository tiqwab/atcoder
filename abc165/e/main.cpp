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
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> ans;
    set<int> used;

    int start = N / 2;
    int end = N / 2 + 1;
    int cnt = 0;
    ans.push_back({start, end});
    used.insert(1 + end - start);
    used.insert(N - (end - start - 1));
    cnt++;
    start--;
    end++;
    while (cnt < M) {
        while (1) {
            // int x = start + N - end;
            // printf("start: %d, end: %d, x: %d\n", start, end, x);
            if (used.find(1 + end - start) != used.end()
                    || used.find(N - (end - start - 1)) != used.end()
                    || end - start == start + N - end) {
                if (end < N) {
                    end++;
                } else {
                    start--;
                }
            } else {
                break;
            }
        }
        assert(start >= 1 && end <= N);
        ans.push_back({start, end});
        used.insert(1 + end - start);
        used.insert(N - (end - start - 1));
        cnt++;
        start--;
        end++;
    }

    for (auto &p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
