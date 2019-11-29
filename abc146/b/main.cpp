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
    int N;
    cin >> N;
    char s[10010];
    cin >> s;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        s[i] = ((s[i] - 'A' + N) % 26) + 'A';
    }

    cout << s << endl;
    
    return 0;
}
