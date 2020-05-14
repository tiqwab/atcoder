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

set<string> words;

int main(void) {
    int N;
    cin >> N;

    string prev;
    cin >> prev;
    words.insert(prev);

    for (int i = 1; i < N; i++) {
        string word;
        cin >> word;
        if (words.find(word) != words.end()) {
            cout << "No" << endl;
            return 0;
        }
        if (prev[(int) prev.size() - 1] != word[0]) {
            cout << "No" << endl;
            return 0;
        }
        words.insert(word);
        prev = word;
    }
    
    cout << "Yes" << endl;
    return 0;
}
