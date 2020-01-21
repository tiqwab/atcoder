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
    int a, b;
    cin >> a >> b;

    int large = max(a, b);
    int small = min(a, b);

    for (int i = 0; i < large; i++) {
        printf("%d", small);
    }
    printf("\n");
    
    return 0;
}
