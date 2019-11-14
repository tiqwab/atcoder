#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define REVERSE(x) reverse((x).begin(), (x).end())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << '\n'
#define endl '\n'

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-10;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct edge{
    int to;
    lint cost;
};

struct node{
    int id;
    lint cost;

    bool operator<(const node& rhs) const {
        return cost > rhs.cost;
    }
};

template<typename T>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    vector< vector<edge> > g(n);
    rreps(i, n - 1){
        g[i].push_back({i - 1, 0LL});
    }

    rep(i, m){
        int l, r;
        lint c;
        cin >> l >> r >> c;
        g[--l].push_back({--r, c});
    }

    vector<lint> cost(n, LLINF);
    cost[0] = 0;
    priority_queue<node> que;
    que.push({0, 0LL});

    while(!que.empty()){
        node now = que.top();
        que.pop();
        if(cost[now.id] < now.cost){
            continue;
        }
        for(auto e : g[now.id]){
            if(chmin(cost[e.to], now.cost + e.cost)){
                que.push({e.to, now.cost + e.cost});
            }
        }
    }

    if(cost[n - 1] < LLINF){
        cout << cost[n - 1] << endl;
    }else{
        cout << -1 << endl;
    }

    cout << flush;

    return 0;
}
