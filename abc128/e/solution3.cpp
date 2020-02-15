#include <algorithm>
#include <iostream>
#include <set>
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

struct obs {
    int s;
    int t;
    int x;
};

vector<struct obs> obss;
vector<int> D;

vector<vector<int>> bs;
vector<vector<int>> es;

// This solution is similar to the third soltuion in the link.
// ref. http://drken1215.hatenablog.com/entry/2019/02/19/110200
// ref. https://imoz.jp/algorithms/imos_method.html
// > 最もシンプルな「いもす法」は 1 次元上に 0 次関数（矩形関数や階段関数などのように上部が平らな関数）を足すものです． 
//
// But the below codes are simpler.
// ref. https://atcoder.jp/contests/abc128/submissions/5655526
// ref. http://drken1215.hatenablog.com/entry/2019/06/15/174200
// ref. https://img.atcoder.jp/abc128/editorial.pdf
int main(void) {
    int N, Q;
    cin >> N >> Q;

    obss.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> obss[i].s >> obss[i].t >> obss[i].x;
    }

    D.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> D[i];
    }

    bs.resize(Q);
    es.resize(Q);
    for (auto &obs : obss) {
        auto it_b = lower_bound(D.begin(), D.end(), obs.s - obs.x);
        auto it_e = lower_bound(D.begin(), D.end(), obs.t - obs.x);
        if (it_b == it_e) {
            continue;
        }
        // printf("[%ld, %ld)\n", it_b - D.begin(), it_e - D.begin());
        if (it_b != D.end()) {
            int pos = it_b - D.begin();
            bs[pos].push_back(obs.x);
        }
        if (it_e != D.end()) {
            int pos = it_e - D.begin();
            es[pos].push_back(obs.x);
        }
    }

    // printf("bs: \n");
    // for (int i = 0; i < Q; i++) {
    //     for (auto &b: bs[i]) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // printf("es: \n");
    // for (int i = 0; i < Q; i++) {
    //     for (auto &e: es[i]) {
    //         cout << e << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    set<int> se;
    for (int i = 0; i < Q; i++) {
        for (auto &e : es[i]) {
            se.erase(e);
        }
        for (auto &b : bs[i]) {
            se.insert(b);
        }

        int ans = se.empty() ? -1 : *se.begin();
        cout << ans << endl;
    }

    return 0;
}
