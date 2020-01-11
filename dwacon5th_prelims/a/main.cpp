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

// TODO: why abs error??
#define abs(x) ((x) > 0 ? (x) : -(x))

int main(void) {
    int N;
    cin >> N;

    vector<double> a(N);
    double sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double avg = sum / ((double) N);

    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (abs(avg - a[i]) < abs(avg - a[ans])) {
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
