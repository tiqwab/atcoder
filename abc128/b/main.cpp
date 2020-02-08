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

class review {
    public:
    string name;
    int score;
    int n;
};

int main(void) {
    int N;
    cin >> N;

    vector<review> reviews;
    reviews.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> reviews[i].name >> reviews[i].score;
        reviews[i].n = i + 1;
    }

    sort(reviews.begin(), reviews.end(), [](const review &a, const review &b) {
            if (a.name != b.name) {
            return a.name < b.name;
            } else {
            return a.score > b.score;
            }
            });

    for (int i = 0; i < N; i++) {
        cout << reviews[i].n << endl;
    }
    
    return 0;
}
