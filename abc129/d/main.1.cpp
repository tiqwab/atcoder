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

vector<string> grid;
vector<vector<int>> count_left;
vector<vector<int>> count_right;
vector<vector<int>> count_up;
vector<vector<int>> count_down;

void setup(const int H, const int W) {
    // left
    for (int i = 0; i < H; i++) {
        int count = 0;
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') {
                count = 0;
            } else {
                count++;
            }
            count_left[i][j] = count;
        }
    }

    // right
    for (int i = 0; i < H; i++) {
        int count = 0;
        for (int j = W - 1; j >= 0; j--) { 
            if (grid[i][j] == '#') {
                count = 0;
            } else {
                count++;
            }
            count_right[i][j] = count;
        }
    }

    // up
    for (int i = 0; i < W; i++) {
        int count = 0;
        for (int j = 0; j < H; j++) {
            if (grid[j][i] == '#') {
                count = 0;
            } else {
                count++;
            }
            count_up[j][i] = count;
        }
    }

    // down
    for (int i = 0; i < W; i++) {
        int count = 0;
        for (int j = H - 1; j >= 0; j--) {
            if (grid[j][i] == '#') {
                count = 0;
            } else {
                count++;
            }
            count_down[j][i] = count;
        }
    }
}

/*
 * solution based on the editiorial.pdf
 */
int main(void) {
    int H, W;
    cin >> H >> W;

    grid.resize(H);
    for (int i = 0; i < H; i++) {
        string S;
        cin >> S;
        grid[i] = S;
    }

    count_left.resize(H, vector<int>(W, 0));
    count_right.resize(H, vector<int>(W, 0));
    count_up.resize(H, vector<int>(W, 0));
    count_down.resize(H, vector<int>(W, 0));

    setup(H, W);

    int maximum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // printf("i = %d, j = %d, left: %d, right: %d, up: %d, down: %d\n",
            //         i, j, count_left[i][j], count_right[i][j], count_up[i][j], count_down[i][j]);
            chmax(maximum, count_left[i][j] + count_right[i][j] + count_up[i][j] + count_down[i][j] - 3);
        }
    }

    cout << maximum << endl;

    return 0;
}
