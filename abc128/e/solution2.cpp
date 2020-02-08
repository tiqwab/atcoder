#include <algorithm>
#include <iostream>
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

// ref. http://tsutaj.hatenablog.com/entry/2017/03/30/224339
// ref. http://beet-aizu.hatenablog.com/entry/2017/12/01/225955
// ref. https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
  typedef Monoid F(Monoid, Monoid);
  typedef Monoid G(Monoid, const OperatorMonoid);
  typedef OperatorMonoid H(const OperatorMonoid, const OperatorMonoid);

  int sz, height;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  F *f;
  G *g;
  H *h;
  const Monoid M1;
  const OperatorMonoid OM0;

  // F: binary operator of data
  // G: apply lazy value to data
  // H: binary operator of lazy values
  // M1: mempty for Monoid
  // OM0: mempty for OperatorMonoid
  LazySegmentTree(int n, F f, G g, H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : M1(M1), OM0(OM0) {
    this->f = f;
    this->g = g;
    this->h = h;
    sz = 1;
    height = 0;
    while(sz < n) sz <<= 1, height++;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  inline void propagate(int k) {
    if(lazy[k] != OM0) {
      lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
      lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      data[k] = reflect(k);
      lazy[k] = OM0;
    }
  }

  inline Monoid reflect(int k) {
    return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
  }

  inline void recalc(int k) {
    while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
  }

  inline void thrust(int k) {
    for(int i = height; i > 0; i--) propagate(k >> i);
  }

  void update(int a, int b, const OperatorMonoid &x) {
    thrust(a += sz);
    thrust(b += sz - 1);
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) lazy[l] = h(lazy[l], x), ++l;
      if(r & 1) --r, lazy[r] = h(lazy[r], x);
    }
    recalc(a);
    recalc(b);
  }

  Monoid query(int a, int b) {
    thrust(a += sz);
    thrust(b += sz - 1);
    Monoid L = M1, R = M1;
    for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) L = f(L, reflect(l++));
      if(r & 1) R = f(reflect(--r), R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};

const int INF = INT_MAX / 2;

class Construction {
    public:
        // cannot pass x between [s, t].
        int s;
        int t;
        int x;
};

vector<Construction> constructions;
vector<int> D;

void solve(LazySegmentTree<int, int> &st, const int N, const int Q) {
    for (int i = 0; i < N; i++) {
        Construction cons = constructions[i];
        int s = max(0, cons.s - cons.x);
        int t = max(0, cons.t - cons.x);
        auto p1 = lower_bound(D.begin(), D.end(), s);
        auto p2 = upper_bound(D.begin(), D.end(), t);
        st.update(distance(D.begin(), p1), distance(D.begin(), p2), cons.x);
    }
}

// solution with lazy segment tree
int main(void) {
    int N, Q;
    cin >> N >> Q;

    constructions.resize(N);
    for (int i = 0; i < N; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        t--;
        constructions[i].s = s;
        constructions[i].t = t;
        constructions[i].x = x;
    }

    D.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> D[i];
    }

    auto f = [](const int a, const int b) { return min(a, b); };
    LazySegmentTree<int, int> st(Q, f, f, f, INF, INF);

    solve(st, N, Q);

    for (int i = 0; i < Q; i++) {
        int ans = st.query(i, i + 1);
        if (ans == INF) {
            cout << "-1" << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}
