#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
    int D;
    cin >> D;
    
    if (D == 22) {
        cout << "Christmas Eve Eve Eve" << endl;
    } else if (D == 23) {
        cout << "Christmas Eve Eve" << endl;
    } else if (D == 24) {
        cout << "Christmas Eve" << endl;
    } else if (D == 25) {
        cout << "Christmas" << endl;
    }

    return 0;
}
