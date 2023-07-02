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

const int MAX_H = 10;
const int MAX_W = 10;

int H_a, W_a;
vector<vector<char>> sheet_a;

int H_b, W_b;
vector<vector<char>> sheet_b;

int H_x, W_x;
vector<vector<char>> sheet_x;

bool check(const int h_a, const int  w_a, const int h_b, const int w_b) {
    if (h_a + H_a > MAX_H * 3) {
        return false;
    }
    if (w_a + W_a > MAX_W * 3) {
        return false;
    }
    if (h_b + H_b > MAX_H * 3) {
        return false;
    }
    if (w_b + W_b > MAX_W * 3) {
        return false;
    }

    vector<vector<char>> field(MAX_H * 3, vector<char>(MAX_W * 3, '.'));

    for (int h = 0; h < H_a; h++) {
        for (int w = 0; w < W_a; w++) {
            if (sheet_a[h][w] == '#') {
                if (h_a + h < 10 || h_a + h >= 10 + H_x || w_a + w < 10 || w_a + w >= 10 + W_x) {
                    return false;
                }
                field[h_a + h][w_a + w] = sheet_a[h][w];
            }
        }
    }

    for (int h = 0; h < H_b; h++) {
        for (int w = 0; w < W_b; w++) {
            if (sheet_b[h][w] == '#') {
                if (h_b + h < 10 || h_b + h >= 10 + H_x || w_b + w < 10 || w_b + w >= 10 + W_x) {
                    return false;
                }
                field[h_b + h][w_b + w] = sheet_b[h][w];
            }
        }
    }

    for (int h = 0; h < H_x; h++) {
        for (int w = 0; w < W_x; w++) {
            if (field[10 + h][10 + w] != sheet_x[h][w]) {
                return false;
            }
        }
    }

    return true;
}

int main(void) {
    cin >> H_a >> W_a;
    for (int i = 0; i < H_a; i++) {
        string s;
        cin >> s;
        vector<char> cs;
        for (int j = 0; j < W_a; j++) {
            cs.push_back(s[j]);
        }
        sheet_a.push_back(cs);
    }

    cin >> H_b >> W_b;
    for (int i = 0; i < H_b; i++) {
        string s;
        cin >> s;
        vector<char> cs;
        for (int j = 0; j < W_b; j++) {
            cs.push_back(s[j]);
        }
        sheet_b.push_back(cs);
    }

    cin >> H_x >> W_x;
    for (int i = 0; i < H_x; i++) {
        string s;
        cin >> s;
        vector<char> cs;
        for (int j = 0; j < W_x; j++) {
            cs.push_back(s[j]);
        }
        sheet_x.push_back(cs);
    }

    for (int h_a = 0; h_a < MAX_H * 3; h_a++) {
        for (int w_a = 0; w_a < MAX_W * 3; w_a++){ 
            for (int h_b = 0; h_b < MAX_H * 3; h_b++) {
                for (int w_b = 0; w_b < MAX_W * 3; w_b++) {
                    if (check(h_a, w_a, h_b, w_b)) {
                        printf("Yes\n");
                        return 0;
                    }
                }
            }
        }
    }

    printf("No\n");
    return 0;
}
