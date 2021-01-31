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

const int MAX_M = 200000;

// {x, y}
vector<pair<ll, ll>> pieces;

auto f1 = []() {
    vector<vector<ll>> f = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    return f;
};

auto f2 = []() {
    vector<vector<ll>> f = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    return f;
};

auto f3 = [](const int p) {
    vector<vector<ll>> f = {{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}};
    return f;
};

auto f4 = [](const int p) {
    vector<vector<ll>> f = {{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}};
    return f;
};

auto fid = []() {
    vector<vector<ll>> f = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    return f;
};

vector<vector<ll>> mult(const vector<vector<ll>> a, const vector<vector<ll>> b) {
    vector<vector<ll>> f(3, vector<ll>(3));
    f[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
    f[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
    f[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
    f[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
    f[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
    f[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
    f[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
    f[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
    f[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
    return f;
}

void print_matrix(vector<vector<ll>> matrix) {
    printf("%lld %lld %lld\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("%lld %lld %lld\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("%lld %lld %lld\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

vector<vector<ll>> ops[MAX_M + 1];

int main(void) {
    int N;
    cin >> N;

    pieces.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    int M;
    cin >> M;

    ops[0] = fid();
    for (int i = 0; i < M; i++) {
        int o;
        cin >> o;

        if (o == 1) {
            ops[i + 1] = mult(f1(), ops[i]);
        } else if (o == 2) {
            ops[i + 1] = mult(f2(), ops[i]);
        } else if (o == 3) {
            int p;
            cin >> p;
            ops[i + 1] = mult(f3(p), ops[i]);
        } else {
            int p;
            cin >> p;
            ops[i + 1] = mult(f4(p), ops[i]);
        }
    }

#ifdef DEBUG
    for (int i = 0; i <= M; i++) {
        printf("ops[%d]:\n", i);
        print_matrix(ops[i]);
    }
    printf("\n");
#endif

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        B--;
        vector<vector<ll>> me = {{pieces[B].first, 0, 0}, {pieces[B].second, 0, 0}, {1, 0, 0}};
        vector<vector<ll>> calculated = mult(ops[A], me);
        printf("%lld %lld\n", calculated[0][0], calculated[1][0]);
    }

    return 0;
}
