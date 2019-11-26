#include <iostream>
#include <vector>

/*
 * ref. https://qiita.com/drken/items/97e37dd6143e33a64c8c
 */

using namespace std;

bool cond(const vector<int> &xs, int ind, int val) {
    return xs[ind] >= val;
}

/*
 * Return the minimum index which satisfies the condition if exists, otherwise -1.
 */
int binary_search(const vector<int> &xs, int val) {
    int left = -1, right = (int) xs.size(), mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (cond(xs, mid, val)) right = mid;
        else left = mid;
    }

    if (right == (int) xs.size()) {
        return -1;
    } else if (xs[right] != val) {
        return -1;
    } else {
        return right;
    }
}

int main(void) {
    int n;
    cin >> n;

    vector<int> xs;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        xs.push_back(x);
    }

    int q;
    cin >> q;

    int count = 0;
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;

        if (binary_search(xs, y) >= 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
