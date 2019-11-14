#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

/*
 * ref. https://www.slideshare.net/chokudai/union-find-49066733
 */
class unionfind {
	vector<int> par, rank;

public:
	void init(int n) {
		par.resize(n);
		rank.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return ;

		if (rank[x] < rank[y]) par[x] = y;
		else {
			par[y] = x;
			if (rank[x] == rank[y]) ++rank[x];
		}
	}
} uf;

void answer(bool f) {
	puts(f ? "Yes" : "No");
	exit(0);
}

int main() {
	int N; cin >> N;
	V<int> A(N), B(N);
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];
	V<pii> sa(N), sb(N);
	rep(i, N) sa[i] = mp(A[i], i);
	rep(i, N) sb[i] = mp(B[i], i);
	sort(ALL(sa)); sort(ALL(sb));

	uf.init(N);

	rep(i, N) {
		if (sa[i].fi > sb[i].fi) {
			answer(0);
		}
		uf.unite(sa[i].se, sb[i].se);
	}

	rep(i, N) {
		if (i > 0 && sa[i].fi <= sb[i-1].fi) {
			answer(1);
		}
		if (uf.find(i) != uf.find(0)) {
			answer(1);
		}
	}
	answer(0);

	return 0;
}
