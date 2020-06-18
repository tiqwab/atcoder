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

const int MAX_N = 200001;
const int MAX_KD = 200001;

// score
multiset<int> scores[MAX_KD];
int infants_kd[MAX_N];
int infants_score[MAX_N];

int main(void) {
    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        b--;
        scores[b].insert(a);
        infants_kd[i] = b;
        infants_score[i] = a;
    }

    // {score, kd}
    set<pair<int, int>> eqs;
    int eqs_kd[MAX_KD];
    for (int i = 0; i < MAX_KD; i++) {
        if (scores[i].size() == 0) {
            continue;
        }
        auto it = scores[i].rbegin();
        eqs.insert({*it, i});
        eqs_kd[i] = *it;
    }

    for (int i = 0; i < Q; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;

        const int id = c;
        const int prev_kd = infants_kd[id];
        const int new_kd = d;
        if (scores[prev_kd].find(infants_score[id]) != scores[prev_kd].end()) {
            // erase of multiset deletes all of elements which has the specified value.
            // Pass the iterator to avoid it.
            // Note that passing the iterator pointing to the end results in the unexpected behavor...
            scores[prev_kd].erase(scores[prev_kd].find(infants_score[id]));
        }
        infants_kd[id] = new_kd;
        scores[new_kd].insert(infants_score[id]);

        eqs.erase({eqs_kd[prev_kd], prev_kd});
        if (scores[prev_kd].size() > 0) {
            auto it = scores[prev_kd].rbegin();
            eqs_kd[prev_kd] = *it;
            eqs.insert({eqs_kd[prev_kd], prev_kd});
        }

        eqs.erase({eqs_kd[new_kd], new_kd});
        if (scores[new_kd].size() > 0) {
            auto it = scores[new_kd].rbegin();
            eqs_kd[new_kd] = *it;
            eqs.insert({eqs_kd[new_kd], new_kd});
        }

        {
            auto it = eqs.begin();
            cout << (*it).first << endl;
        }
    }

    return 0;
}
