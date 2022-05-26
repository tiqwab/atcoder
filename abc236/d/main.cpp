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

vector<vector<int>> matrix;

int calc(const vector<int> &v) {
    int ans = 0;
    for (int i = 0; i < (int) v.size(); i += 2) {
        ans = ans ^ matrix[v[i]][v[i + 1]];
    }
    return ans;
}

void dfs(const vector<int> acc, const set<int> numbers, int &ans, const int N) {
    const auto n = (int) acc.size();
    if (n == N) {
#ifdef DEBUG
        for (int i = 0; i < N; i++) {
            printf("%d ", acc[i]);
        }
#endif
        const int cand = calc(acc);
#ifdef DEBUG
        printf(": %d\n", cand);
#endif
        chmax(ans, cand);
        return;
    }

    if (n % 2 == 0) {
        vector<int> next_acc = acc;
        set<int> next_numbers = numbers;
        const int elem = *(next_numbers.begin());
        next_numbers.erase(next_numbers.find(elem));
        next_acc.push_back(elem);
        dfs(next_acc, next_numbers, ans, N);
    } else {
        for (auto num : numbers) {
            vector<int> next_acc = acc;
            set<int> next_numbers = numbers;
            next_numbers.erase(next_numbers.find(num));
            next_acc.push_back(num);
            dfs(next_acc, next_numbers, ans, N);
        }
    }
}

int main(void) {
    int N;
    cin >> N;
    N *= 2;

    matrix.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int x;
            cin >> x;
            matrix[i][j] = x;
            matrix[j][i] = x;
        }
    }
#ifdef DEBUG
    printf("matrix: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
#endif

    int ans = 0;

    vector<int> acc;
    set<int> numbers;
    for (int i = 0; i < N; i++) {
        numbers.insert(i);
    }
    dfs(acc, numbers, ans, N);

    cout << ans << endl;
    return 0;
}
