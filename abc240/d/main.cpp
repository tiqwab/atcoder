#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

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

// {ballNumber, quantity}
vector<pair<int, int>> stack;

int main(void) {
    int N;
    cin >> N;

    vector<int> as;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        as.push_back(a);
    }

    stack.push_back(make_pair(as[0], 1));
    int acc = 1;
    printf("%d\n", acc);

    auto push = [&](const pair<int, int> entry) {
        stack.push_back(entry);
        acc += entry.second;
    };

    auto pop = [&]() {
        const auto entry = stack.back();
        acc -= entry.second;
        stack.pop_back();
    };

    for (int i = 1; i < N; i++) {
        const int a = as[i];
        const auto prev_entry = stack.back();
        const int prev_a = prev_entry.first;
        const int prev_quantity = prev_entry.second;
        pop();

        if (a == prev_a) {
            if (prev_quantity + 1 < a) {
                push(make_pair(a, prev_quantity + 1));
            }
        } else {
            push(prev_entry);
            push(make_pair(a, 1));
        }

        printf("%d\n", acc);
    }

    return 0;
}
