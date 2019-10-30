#include <iostream>

int main() {
    using namespace std;

    int a, b, ans;

    cin >> a >> b;

    ans = max(0, a - 2 * b);
    cout << ans << endl;

    return 0;
}
