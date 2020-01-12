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

    // title, length
    vector<pair<string, int>> songs(N);
    for (int i = 0; i < N; i++) {
        string s;
        int t;
        cin >> s >> t;
        songs[i] = {s, t};
    }

    string X;
    cin >> X;

    int i;
    for (i = 0; i < N; i++) {
        if (songs[i].first == X) {
            break;
        }
    }

    int ans = 0;
    for (int j = i + 1; j < N; j++) {
        ans += songs[j].second;
    }

    cout << ans << endl;

    return 0;
}
