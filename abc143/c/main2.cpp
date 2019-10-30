#include <iostream>

int main(void) {
    using namespace std;

    int n;
    string s;

    cin >> n >> s;

    int count = 1;
    char prev = s[0];

    for (int i = 1; i < n; i++) {
        if (prev != s[i]) {
            count++;
            prev = s[i];
        }
    }

    cout << count << endl;

    return 0;
}
