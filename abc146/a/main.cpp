#include <iostream>

#include <string.h>

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
    char s[8];
    cin >> s;
    
    if (strcmp(s, "SUN") == 0) {
        cout << 7 << endl;
    } else if (strcmp(s, "MON") == 0) {
        cout << 6 << endl;
    } else if (strcmp(s, "TUE") == 0) {
        cout << 5 << endl;
    } else if (strcmp(s, "WED") == 0) {
        cout << 4 << endl;
    } else if (strcmp(s, "THU") == 0) {
        cout << 3 << endl;
    } else if (strcmp(s, "FRI") == 0) {
        cout << 2 << endl;
    } else if (strcmp(s, "SAT") == 0) {
        cout << 1 << endl;
    }
    
    return 0;
}
