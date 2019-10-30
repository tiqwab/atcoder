#include <cfloat>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 600;
const int MAX_M = 179700;

class Edge {
    public:
        int from;
        int to;
};

int n, m;
map<int, vector<Edge> > edges;

double dp[MAX_N][MAX_N];

void calc_dp(int room_no, int block_room_no) {
    for (int i = room_no - 1; i >= 0; i--) {
        vector<Edge> es = edges[i+1];
        double sum = 0;
        // cout << "start: " << room_no << endl;
        for (auto it = es.begin(); it != es.end(); it++) {
            Edge e = *it;
            // cout << dp[0][e.to - 1] << endl;
            sum += dp[block_room_no-1][e.to - 1];
        }
        dp[block_room_no-1][i] = 1.0 + sum / ((double) es.size());
    }
}

int main(void) {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s, t;
        Edge edge;
        cin >> s >> t;
        edge.from = s;
        edge.to = t;
        edges[s].push_back(edge);
    }

    calc_dp(n-1, n);

    for (int i = n-1; i >= 0; i--) {
        for (int j = i-1; j >= 0; j--) {
            dp[j][i] = dp[n-1][i];
        }
    }

    for (int i = n-2; i >= 0; i--) {
        vector<Edge> es = edges[i+1];
        Edge e;
        double max_cost = 0;
        double sum = 0;
        if (es.size() <= 1) {
            continue;
        }
        for (auto it = es.begin(); it != es.end(); it++) {
            e = *it;
            sum += dp[n-1][e.to - 1];
            if (dp[n-1][e.to - 1] > max_cost) {
                max_cost = dp[n-1][e.to - 1];
            }
        }
        dp[i][i] = 1.0 + (sum - max_cost) / ((double) es.size() - 1);

        calc_dp(i, i+1);
    }

    // Print edges
    // for (auto it = edges.begin(); it != edges.end(); it++) {
    //     vector<Edge> es = (*it).second;
    //     cout << (*it).first << ":" << endl;
    //     for (auto it2 = es.begin(); it2 != es.end(); it2++) {
    //         cout << (*it2).from << "->" << (*it2).to << endl;
    //     }
    // }

    // Print dp_i,n
    // for (int i = 0; i < n; i++) {
    //     cout << dp[n-1][i] << endl;
    // }

    // Print dp
    // cout << "dp: " << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%3.6f ", dp[i][j]);
    //     }
    //     cout << endl;
    // }

    double answer = DBL_MAX;
    for (int i = 0; i < n; i++) {
        if (dp[i][0] != 0 && dp[i][0] < answer) {
            answer = dp[i][0];
        }
    }

    printf("%3.6f\n", answer);

    return 0;
}
