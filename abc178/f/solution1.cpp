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

vector<int> as;
vector<int> bs;

// {num, cnt}
map<int, int> cnt_for_num;
map<int, int> cnt_for_num_a;
map<int, int> cnt_for_num_b;

// pos_for_cnt_a[i] is set for nums which appears i times
map<int, set<int>> nums_for_cnt;
map<int, set<int>> nums_for_cnt_a;
map<int, set<int>> nums_for_cnt_b;

// ref. YouTube
int main(void) {
    int N;
    cin >> N;

    as.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> as[i];
        cnt_for_num[as[i]]++;
        cnt_for_num_a[as[i]]++;
    }

    bs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
        cnt_for_num[bs[i]]++;
        cnt_for_num_b[bs[i]]++;
    }

    {
        bool ok = true;
        for (auto p : cnt_for_num) {
            nums_for_cnt[p.second].insert(p.first);
            if (p.second > N) {
                ok = false;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    for (auto p : cnt_for_num_a) {
        nums_for_cnt_a[p.second].insert(p.first);
    }

    for (auto p : cnt_for_num_b) {
        nums_for_cnt_b[p.second].insert(p.first);
    }

#ifdef DEBUG
    printf("cnt_for_num_a: \n");
    for (auto p : nums_for_cnt_a) {
        printf("  %d: ", p.first);
        for (auto x : p.second) {
            printf("%d ", x);
        }
        cout << endl;
    }
    printf("cnt_for_num_b: \n");
    for (auto p : nums_for_cnt_b) {
        printf("  %d: ", p.first);
        for (auto x : p.second) {
            printf("%d ", x);
        }
        cout << endl;
    }
#endif

    vector<vector<int>> ans(N + 1);

    auto get_any_other_than = [&](const int elem, map<int, int> &cnt_for_me) {
        for (auto p : cnt_for_me) {
            if (p.first == elem) continue;
            return p.first;
        }
        printf("couldn't get_any_other_than(%d)\n", elem);
        abort();
    };

    for (int i = N; i > 0; i--) {
        auto nums_appearing_at_i_times = nums_for_cnt[i];
        auto it = nums_appearing_at_i_times.begin();
        int x = -1, y = -1;
        switch (nums_appearing_at_i_times.size()) {
            case 0:
                x = get_any_other_than(y, cnt_for_num_a);
                y = get_any_other_than(x, cnt_for_num_b);
                break;
            case 1:
                x = *it;
                if (cnt_for_num_a.find(x) == cnt_for_num_a.end()) {
                    swap(x, y);
                    x = get_any_other_than(y, cnt_for_num_a);
                } else {
                    y = get_any_other_than(x, cnt_for_num_b);
                }
                break;
            case 2:
                x = *it++;
                y = *it;
                if (cnt_for_num_a.find(x) == cnt_for_num_a.end()) {
                    swap(x, y);
                }
                break;
            default:
                cerr << "error: nums_appearing_at_i_times > 2" << endl;
                abort();
        }

        ans[x].push_back(y);

        auto remove_num = [&](int num, map<int, int> &cnt_for_me, map<int, set<int>> &nums_for_me) {
            nums_for_cnt[cnt_for_num[num]].erase(num);
            nums_for_me[cnt_for_me[num]].erase(num);

            cnt_for_num[num]--;
            if (cnt_for_num[num] == 0) {
                cnt_for_num.erase(num);
            } else {
                nums_for_cnt[cnt_for_num[num]].insert(num);
            }

            cnt_for_me[num]--;
            if (cnt_for_me[num] == 0) {
                cnt_for_me.erase(num);
            } else {
                nums_for_me[cnt_for_me[num]].insert(num);
            }
        };

        remove_num(x, cnt_for_num_a, nums_for_cnt_a);
        remove_num(y, cnt_for_num_b, nums_for_cnt_b);

#ifdef DEBUG
    printf("cnt_for_num_a: \n");
    for (auto p : nums_for_cnt_a) {
        printf("  %d: ", p.first);
        for (auto x : p.second) {
            printf("%d ", x);
        }
        cout << endl;
    }
#endif

#ifdef DEBUG
    printf("cnt_for_num_b: \n");
    for (auto p : nums_for_cnt_b) {
        printf("  %d: ", p.first);
        for (auto x : p.second) {
            printf("%d ", x);
        }
        cout << endl;
    }
#endif
    }

    for (int i = 0; i < N; i++) {
        cout << ans[as[i]].back() << " ";
        ans[as[i]].pop_back();
    }
    cout << endl;

    return 0;
}
