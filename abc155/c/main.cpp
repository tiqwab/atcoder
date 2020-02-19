#include <algorithm>
#include <iostream>
#include <map>
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

    map<string, int> m;
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        m[S]++;
        chmax(maximum, m[S]);
    }

    vector<string> xs; 
    for (auto &p : m) {
        if (p.second == maximum) {
            xs.push_back(p.first);
        }
    }
    sort(xs.begin(), xs.end());

    for (auto &x : xs) {
        cout << x << endl;
    }

    return 0;
}
