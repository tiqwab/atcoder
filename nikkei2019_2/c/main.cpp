#include <algorithm>
#include <iostream>
#include <queue>

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

class Elem {
    public:
        int value;
        int orig_pos;

        bool operator < (const Elem &other) const {
            return value < other.value;
        }

        bool operator > (const Elem &other) const {
            return value > other.value;
        }
};

const int MAX_N = 100000;

int n;
Elem a[MAX_N];
Elem b[MAX_N];

int tmp[MAX_N];

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i].value << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i].value << " ";
    }
    cout << endl;
}

void input(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = {x, i};
    }
}

/*
 * Sort b and swap corresponding eleements in a.
 */
void sort_b() {
    sort(&b[0], &b[n]);

    for (int i = 0; i < n; i++) {
        a[b[i].orig_pos].orig_pos = i;
        b[i].orig_pos = i;
    }
}

int count_cycles() {
    int arrow[MAX_N];
    bool visited[MAX_N];
    queue<int> que;
    int count = 0;

    for (int i = 0; i < n; i++) {
        arrow[a[i].orig_pos] = i;
        visited[i] = false;
        que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        int next;
        que.pop();
        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        while (1) {
            next = arrow[cur];
            if (visited[next]) {
                break;
            }
            visited[next] = true;
            cur = next;
        }
        count++;
    }

    return count;
}

int main(void) {
    input();

    sort_b();

    sort(&a[0], &a[n]);
    for (int i = 0; i < n; i++) {
        if (a[i].value > b[i].value) {
            cout << "No" << endl;
            return 0;
        }
    }

    int cycles = count_cycles();

    if (cycles > 1) {
        cout << "Yes" << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (b[i].value >= a[i + 1].value ){ 
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
