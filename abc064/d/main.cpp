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

void left_turn(int &idx, vector<char> &ans, const string &S, const int N) {
    // printf("left_turn start, idx: %d\n", idx);
    while (idx < N) {
        if (S[idx] == ')') {
            idx++;
            break;
        } else {
            ans.push_back('(');
            idx++;
            left_turn(idx, ans, S, N);
            ans.push_back(')');
        }
    }
    // printf("left_turn end, idx: %d\n", idx);
}

void solve(vector<char> &ans, const string &S, const int N) {
    int idx = 0;
    while (idx < N) {
        if (S[idx] == '(') {
            ans.push_back('(');
            idx++;
            left_turn(idx, ans, S, N);
            ans.push_back(')');
        } else {
            idx++;
            ans.insert(ans.begin(), '(');
            ans.push_back(')');
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<char> ans;
    solve(ans, S, N);

    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
