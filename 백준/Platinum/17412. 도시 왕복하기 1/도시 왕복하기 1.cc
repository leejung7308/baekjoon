#include <bits/stdc++.h>
#include <unordered_map>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
#define MAX 1000000
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<vector<int>> graph;
vector<vector<int>> capacity, flow;
int n, p;
int answer = 0;
void edmonds_karp() {
    while (1) {
        queue<int> q;
        q.push(1);
        vector<int> parent(n + 1, -1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                if (capacity[cur][next] - flow[cur][next] > 0 && parent[next] == -1) {
                    q.push(next);
                    parent[next] = cur;
                    if (next == 2) break;
                }
            }
        }
        if (parent[2] == -1) break;
        int minflow = INF;
        for (int i = 2; i != 1; i = parent[i]) minflow = min(minflow, capacity[parent[i]][i] - flow[parent[i]][i]);
        for (int i = 2; i != 1; i = parent[i]) {
            flow[parent[i]][i] += minflow;
            flow[i][parent[i]] -= minflow;
        }
        answer++;
    }
}
int main() {
    FAST_IO;
    cin >> n >> p;
    graph.resize(n + 1);
    capacity.resize(n + 1, vector<int>(n + 1));
    flow.resize(n + 1, vector<int>(n + 1));
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        capacity[a][b] = 1;
    }
    edmonds_karp();
    cout << answer;
}