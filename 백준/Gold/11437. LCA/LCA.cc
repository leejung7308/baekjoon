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
int n, m;
int a, b;
vector<vector<int>> edges;
vector<int> parent, level;
void setTree() {
    parent.resize(n + 1);
    level.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    level[1] = 1;
    queue<int> q;
    vector<bool> visited(n + 1);
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : edges[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            level[next] = level[cur] + 1;
            parent[next] = cur;
            q.push(next);
        }
    }
}
void Solution() {
    if (level[a] > level[b]) swap(a, b);
    while (level[a] != level[b]) b = parent[b];
    while (a != b) a = parent[a], b = parent[b];
}
void Input() {
    cin >> n;
    edges.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    setTree();
    cin >> m;
    while (m--) {
        cin >> a >> b;
        Solution();
        cout << a << '\n';
    }
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
    }
}