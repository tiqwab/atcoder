#include <iostream>
#include <vector>

#define MAX_N 50

int main(void) {
    using namespace std;

    int n;
    cin >> n;

    vector<int> score(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        score[i] = x;
    }

    int sum = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            sum += score[i] * score[j];
        }
    }

    cout << sum << endl;

    return 0;
}
