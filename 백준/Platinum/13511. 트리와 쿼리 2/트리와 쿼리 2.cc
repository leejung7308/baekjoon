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
#define pii pair<int, LL>
using namespace std;
int n, u, v, w, m, k, depth;
vector<vector<pii>> graph;
vector<int> level;
vector<vector<pii>> parent;
void setTree() {
    vector<bool> visited(n + 1);
    queue<int> q;
    visited[1] = true;
    level[1] = 1;
    int cur = 1;
    q.push(1);
    while (!q.empty()) {
        cur = q.front();
        int lev = level[cur];
        q.pop();
        for (pii next : graph[cur]) {
            int ni = next.first;
            int c = next.second;
            if (visited[ni]) continue;
            visited[ni] = true;
            level[ni] = lev + 1;
            parent[ni][0] = { cur,c };
            q.push(ni);
        }
    }
    depth = cur;
}
void setSparseTable() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 2; j <= n; j++) {
            pii prev = parent[j][i - 1];
            parent[j][i] = parent[prev.first][i - 1];
            parent[j][i].second += prev.second;
        }
    }
}
void Input() {
    cin >> n;
    graph.resize(n + 1);
    parent.resize(n + 1,vector<pii>(21));
    level.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i][0] = { i,0 };
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    setTree();
    setSparseTable();
    cin >> m;
}
LL getCost() {
    LL ret = 0;
    int a = u, b = v;
    if (level[a] > level[b]) swap(a, b);
    while (level[a] != level[b]) { //동일 레벨로 맞추기
        for (int i = 0; i < parent[b].size(); i++) {
            if (level[parent[b][i].first] < level[a]) {
                ret += parent[b][i - 1].second;
                b = parent[b][i - 1].first;
                break;
            }
            else if (level[parent[b][i].first] == level[a]) {
                ret += parent[b][i].second;
                b = parent[b][i].first;
                break;
            }
        }
    }
    while (a != b) {
        for (int i = parent[a].size() - 1; i >= 0; i--) {
            if (parent[a][i].first != parent[b][i].first) {
                ret += parent[a][i].second;
                ret += parent[b][i].second;
                a = parent[a][i].first;
                b = parent[b][i].first;
                break;
            }
            if (i == 0) {
                ret += parent[a][i].second;
                ret += parent[b][i].second;
                return ret;
            }
        }
    }
    return ret;
}
int getK() {
    int a = u, b = v, lca = -1;
    if (level[a] > level[b]) swap(a, b);
    while (level[a] != level[b]) { //동일 레벨로 맞추기
        for (int i = 0; i < parent[b].size(); i++) {
            if (level[parent[b][i].first] < level[a]) {
                b = parent[b][i - 1].first;
                break;
            }
            else if (level[parent[b][i].first] == level[a]) {
                b = parent[b][i].first;
                break;
            }
        }
    }
    while (a != b) {
        for (int i = parent[a].size() - 1; i >= 0; i--) {
            if (parent[a][i].first != parent[b][i].first || i == 0) {
                a = parent[a][i].first;
                b = parent[b][i].first;
                break;
            }
        }
    }
    lca = a;
    int dest = -1;
    int start = -1;
    if (level[u] - level[lca] + 1 >= k) dest = level[u] - k + 1, start = u;
    else dest = level[lca] + (k - (level[u] - level[lca] + 1)), start = v;
    while (level[start] != dest) {
        for (int i = parent[start].size() - 1; i >= 0; i--) {
            if (level[parent[start][i].first] >= dest) {
                start = parent[start][i].first;
                break;
            }
        }
    }
    return start;
}
void Solution() {
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            cout << getCost() << '\n';
        }
        else {
            cin >> u >> v >> k;
            cout << getK() << '\n';
        }
    }
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}