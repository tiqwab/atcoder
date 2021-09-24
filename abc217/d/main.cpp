#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>
#include <string.h>

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

// The definition of SkiplistList comes from https://github.com/spinute/ods, which is
// distributed under under a Creative Commons Attribution license.
// The full text of the license is available here.
//
// http://creativecommons.org/licenses/by/2.5/ca/

template<class T>
class SkiplistList {
protected:
	T null;
	struct Node {
		T x;
		int height;
		int *length;
		Node **next;
	};
	Node *sentinel;
	int h;
	int n;

	Node *newNode(T x, int h) {
		Node *u = new Node;
		u->x = x;
		u->height = h;
		u->length = new int[h+1];
		u->next = new Node*[h+1];
		return u;
	}
	void deleteNode(Node *u) {
		delete[] u->length;
		delete[] u->next;
		delete u;
	}

	Node* findPred(int i) {
		Node *u = sentinel;
		int r = h;
		int j = -1;   // リスト 0 における現在のノードのインデックス
		while (r >= 0) {
			while (u->next[r] != NULL && j + u->length[r] < i) {
				j += u->length[r];
				u = u->next[r];
			}
			r--;
		}
		return u;
	}

	Node* add(int i, Node *w) {
		Node *u = sentinel;
		int k = w->height;
		int r = h;
		int j = -1; // u のインデックス
		while (r >= 0) {
			while (u->next[r] != NULL && j + u->length[r] < i) {
				j += u->length[r];
				u = u->next[r];
			}
			u->length[r]++; // 新たなノードがリスト 0 において何番めなのかを数える
			if (r <= k) {
				w->next[r] = u->next[r];
				u->next[r] = w;
				w->length[r] = u->length[r] - (i - j);
				u->length[r] = i - j;
			}
			r--;
		}
		n++;
		return u;
	}

public:
	SkiplistList();
	virtual ~SkiplistList();

    // O(log(n))
	T get(int i) {
		return findPred(i)->next[0]->x;
	}

    // O(log(n))
	T set(int i, T x) {
		Node *u = findPred(i)->next[0];
		T y = u->x;
		u->x = x;
		return y;
	}

    // O(log(n))
	void add(int i, T x) {
		Node *w = newNode(x, pickHeight());
		if (w->height > h)
			h = w->height;
		add(i, w);
	}

    // O(log(n))
	T remove(int i) {
		T x = null;
		Node *u = sentinel, *del;
		int r = h;
		int j = -1; // u のインデックス
		while (r >= 0) {
			while (u->next[r] != NULL && j + u->length[r] < i) {
				j += u->length[r];
				u = u->next[r];
			}
			u->length[r]--; // ノードを削除するので、辺の長さを減らす
			if (j + u->length[r] + 1 == i && u->next[r] != NULL) {
				x = u->next[r]->x;
				u->length[r] += u->next[r]->length[r];
				del = u->next[r];
				u->next[r] = u->next[r]->next[r];
				if (u == sentinel && u->next[r] == NULL)
					h--;
			}
			r--;
		}
		deleteNode(del);
		n--;
		return x;
	}

	int pickHeight() {
		int z = rand();
		int k = 0;
		int m = 1;
		while ((z & m) != 0) {
			k++;
			m <<= 1;
		}
		return k;
	}

	void clear() {
		Node *u = sentinel->next[0];
		while (u != NULL) {
			Node *n = u->next[0];
			deleteNode(u);
			u = n;
		}
		memset(sentinel->next, '\0', sizeof(Node*)*h);
		h = 0;
		n = 0;
	}

	int size() {
		return n;
	}


};

template<class T>
SkiplistList<T>::SkiplistList() {
	null = (T)NULL;
	n = 0;
	sentinel = newNode(null, sizeof(int)*8);
	memset(sentinel->next, '\0', sizeof(Node*)*sentinel->height);
	h = 0;
}

template<class T>
SkiplistList<T>::~SkiplistList() {
	clear();
	deleteNode(sentinel);
}
int main(void) {
    int L, Q;
    cin >> L >> Q;

    // left side of each part
    SkiplistList<int> ls;
    ls.add(ls.size(), 0);
    ls.add(ls.size(), L);
    for (int i = 0; i < Q; i++) {
        int c, x;
        cin >> c >> x;
        if (c == 1) {
            int l = 0, r = (int) ls.size();
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (x > ls.get(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            ls.add(r, x);
        } else if (c == 2) {
            int l = 0, r = (int) ls.size();
            while (r - l > 1) {
                int mid = l + (r - l) / 2;
                if (x > ls.get(mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            printf("%d\n", ls.get(r) - ls.get(l));
        }
    }

    return 0;
}
