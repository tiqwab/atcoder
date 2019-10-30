#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;

    cin >> n;

    vector<int> ls(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ls[i] = x;
    }

    sort(ls.begin(), ls.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int id1 = lower_bound(ls.begin(), ls.end(), ls[i] + ls[j]) - ls.begin();
            int d = id1 - j - 1;
            count += d;
        }
    }

    cout << count << endl;

    return 0;
}
