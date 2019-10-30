#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

class Entry {
    public:
        int cost;
        int hp;

        bool operator< (const Entry &other) const {
            return cost * hp < other.cost * other.hp;
        }
};

int main(void) {
    ll n, k;

    cin >> n >> k;

    vector<ll> as(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        as[i] = x;
    }

    vector<ll> fs(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        fs[i] = x;
    }

    sort(as.begin(), as.end());
    sort(fs.begin(), fs.end(), [](const int &a, const int &b) { return a > b; });

    // for (int i = 0; i < n; i++) {
    //     cout << as[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     cout << fs[i] << " ";
    // }
    // cout << endl;

    vector<Entry> entries(n);
    for (int i = 0; i < n; i++) {
        entries[i].cost = as[i];
        entries[i].hp = fs[i];
    }

    priority_queue<Entry> que;

    for (int i = 0; i < n; i++) {
        que.push(entries[i]);
    }

    for (int i = 0; i < k; i++) {
        Entry entry = que.top();
        que.pop();
        if (entry.cost > 0) {
            entry.cost--;
            que.push(entry);
        } else {
            break;
        }
    }

    Entry entry = que.top();
    cout << entry.cost * entry.hp << endl;

    return 0;
}
