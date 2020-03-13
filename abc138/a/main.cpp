#include <iostream>

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
    int a;
    char s[16];

    cin >> a;

    if (a >= 3200) {
        cin >> s;
        cout << s << endl;
    } else {
        cout << "red" << endl;
    }
    
    return 0;
}
