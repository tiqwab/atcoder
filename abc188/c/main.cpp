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

// {id, rate}
vector<pair<int, int>> as;

int main(void) {
    int levels;
    cin >> levels;

    const int num_players = 1 << levels;

    as.resize(num_players);
    for (int i = 0; i < num_players; i++) {
        int a;
        cin >> a;
        as[i] = make_pair(i + 1, a);
    }

    for (int i = 0; i < levels - 1; i++) {
        vector<pair<int, int>> tmp;
#ifdef DEBUG
        printf("as: ");
        for (auto a : as) {
            cout << a.second << " ";
        }
        printf("\n");
#endif

        for (int j = 0; j < (int) as.size(); j += 2) {
            auto one = as[j];
            auto two = as[j + 1];
            if (one.second > two.second) {
                tmp.push_back(one);
            } else {
                tmp.push_back(two);
            }
        }

        swap(as, tmp);
    }

    assert(as.size() == 2);
    if (as[0].second > as[1].second) {
        cout << as[1].first << endl;
    } else {
        cout << as[0].first << endl;
    }

    return 0;
}
