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

// {unit, deadline}
vector<pair<ll, ll>> tasks;

int main(void) {
    ll N;
    cin >> N;

    tasks.resize(N);
    for (int i = 0; i < N; i++) {
        ll A, B;
        cin >> A >> B;
        tasks[i] = {A, B};
    }
    sort(tasks.begin(), tasks.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
            });

    // for (auto &p : tasks) {
    //     cout << p.first << "," << p.second << endl;
    // }

    ll acc = 0;
    bool can_finish = true;
    for (int i = 0; i < N; i++) {
        acc += tasks[i].first;
        if (acc > tasks[i].second) {
            can_finish = false;
            break;
        }
    }

    if (can_finish) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
