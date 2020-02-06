#include <algorithm>
#include <iostream>
#include <vector>

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

int rank[9];

int main(void) {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a < 3200) {
            rank[a / 400]++;
        } else {
            rank[8]++;
        }
    }

    int acc = 0;
    for (int i = 0; i < 8; i++) {
        if (rank[i] > 0) {
            acc++;
        }
    }

    int minimum = (acc == 0 && rank[8] > 0) ? 1 : acc;
    int maximum = acc + rank[8];

    std::cout << minimum << " " << maximum << std::endl;

    return 0;
}
