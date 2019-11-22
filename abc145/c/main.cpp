#include <cmath>
#include <iostream>
#include <vector>

#include <stdio.h>

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

#define MAX_N 8

class Point {
    public:
        double x;
        double y;
};

int fact(int n) {
    if (n > 1) {
        return n * fact(n - 1);
    } else {
        return 1;
    }
}

double calc(const vector<Point> &visited) {
    double acc = 0;
    for (int i = 0; i < (int) visited.size() - 1; i++) {
        acc += sqrt(pow(visited[i].x - visited[i + 1].x, 2) + pow(visited[i].y - visited[i + 1].y, 2));
    }
    return acc;
}

void solve(vector<bool> &memo, const vector<Point> &points, vector<Point> visited, const int n, double *acc) {
    if ((int) visited.size() == n) {
        *acc = *acc + calc(visited);
    }
    for (int i = 0; i < n; i++) {
        if (!memo[i]) {
            memo[i] = true;
            visited.push_back(points[i]);
            solve(memo, points, visited, n, acc);
            visited.pop_back();
            memo[i] = false;
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    vector<Point> points(n);
    vector<bool> memo(n, false);

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    double acc = 0;
    solve(memo, points, vector<Point>(), n, &acc);

    printf("%10.7f\n", acc / fact(n));

    return 0;
}

