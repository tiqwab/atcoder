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

int main(void) {
    string X;
    cin >> X;
    int N;
    cin >> N;

    map<char, char> conv;
    for (int i = 0; i < 26; i++) {
        char c = X[i];
        conv[c] = 'a' + i;
    }

    // {after conversion, before conversion}
    vector<pair<string, string>> people(N);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        people[i].first = S;
        people[i].second = S;
        for (int j = 0; j < (int) S.size(); j++) {
            people[i].first[j] = conv[people[i].first[j]];
        }
    }

#ifdef DEBUG
    printf("people: \n");
    for (int i = 0; i < N; i++) {
        cout << people[i].first << " " << people[i].second << endl;
    }
    printf("\n");
#endif

    sort(people.begin(), people.end());

    for (int i = 0; i < N; i++) {
        printf("%s\n", people[i].second.c_str());
    }

    return 0;
}
