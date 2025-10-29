#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
using namespace std;
int n, p, ans = 0;
vector<int> level, work;
vector<vector<int>> graph, capacity, flow;
bool bfs() {
    level = vector<int>(2 * n + 1, -1);
    level[n + 1] = 0;
    queue<int> q;
    q.push(n + 1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : graph[cur]) {
            if (level[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
                level[next] = level[cur] + 1;
                q.push(next);
            }
        }
    }
    return level[2] != -1;
}
int dfs(int cur) {
    if (cur == 2) return 1;
    for (int& i = work[cur]; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (level[next] != level[cur] + 1 || capacity[cur][next] - flow[cur][next] <= 0) continue;
        if (dfs(next)) {
            flow[cur][next]++;
            flow[next][cur]--;
            return 1;
        }
    }
    return 0;
}
int main() {
    FAST_IO;
    cin >> n >> p;
    graph.resize(n * 2 + 1);
    capacity = flow = vector<vector<int>>(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= n; i++) {
        graph[i].push_back(n + i);
        graph[n + i].push_back(i);
        capacity[i][n + i] = 1;
    }
    while (p--) {
        int a, b;
        cin >> a >> b;
        graph[n + a].push_back(b);
        graph[a].push_back(n + b);
        graph[n + b].push_back(a);
        graph[b].push_back(n + a);
        capacity[n + a][b] = capacity[n + b][a] = 1;
    }
    while (bfs()) {
        work = vector<int>(2 * n + 1);
        while (dfs(n + 1)) ans++;
    }
    cout << ans;
}