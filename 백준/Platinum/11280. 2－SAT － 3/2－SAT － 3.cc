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
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<vector<int>> graph, sccs;
vector<int> visited;
vector<bool> isScc;
stack<int> st;
int n, m, idx = 0;
int Not(int x) {
    if (x <= n) return x + n;
    else return x - n;
}
int dfs(int cur) {
    visited[cur] = ++idx;
    int ret = visited[cur];
    st.push(cur);
    for (int next : graph[cur]) {
        if (!visited[next]) ret = min(ret, dfs(next));
        else if (!isScc[next]) ret = min(ret, visited[next]);
    }
    if (ret == visited[cur]) {
        int tmp;
        vector<int> scc;
        while (true) {
            tmp = st.top();
            st.pop();
            isScc[tmp] = true;
            scc.push_back(tmp);
            if (tmp == cur) break;
        }
        sccs.push_back(scc);
    }
    return ret;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    graph.resize(2 * n + 1);
    visited.resize(2 * n + 1, 0);
    isScc.resize(2 * n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < 0) a = -a;
        else a = n + a;
        if (b < 0) b = n + -b;
        graph[a].push_back(b);
        graph[Not(b)].push_back(Not(a));
    }
    for (int i = 1; i <= n * 2; i++) if (!visited[i]) dfs(i);

    for (const auto& scc : sccs) {
        vector<bool> vis(2 * n + 1);
        for (int i : scc) {
            if (vis[Not(i)]) {
                cout << 0;
                return 0;
            }
            vis[i] = true;
        }
    }
    cout << 1;
}