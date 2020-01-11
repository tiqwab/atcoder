#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(const ll sx, const ll sy) {
    ll x = min(sx, sy);
    ll y = max(sx, sy);
    ll tmp;
    while (x > 0) {
        tmp = y;
        y = x;
        x = tmp % x;
    }
    return y;
}

ll lcm(const ll x, const ll y) {
    return x / gcd(x, y) * y;
}

// ref. http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0005
int main(void) {
    char buf[1024];
    int res;
    while (1) {
        if (fgets(buf, 1024, stdin) == NULL) {
            if (feof(stdin)) {
                return 0;
            } else {
                perror("fgets");
                return 1;
            }
        }

        ll x, y;
        sscanf(buf, "%lld %lld", &x, &y);
        cout << gcd(x, y) << " " << lcm(x, y) << endl;
    }
}
