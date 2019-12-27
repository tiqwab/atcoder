#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

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
    string s;
    cin >> s;

    map<char, int> m;
    char a;
    for (int i = 0; i < (int) s.size(); i++) {
        m[s[i]]++;
        a = s[i];
    }

    if ((int) m.size() != 2) {
        cout << "No" << endl;
        return 0;
    }
    if (m[a] != 2) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}
