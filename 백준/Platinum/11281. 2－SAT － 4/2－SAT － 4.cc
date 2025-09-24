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
int n, m;
vector<unordered_set<int>> graph;
vector<vector<int>> answer;
vector<int> visited, scc;
stack<int> st;
int idx = 0, sccCnt = 0;
int dfs(int cur) {
    visited[cur] = idx++;
    int ret = visited[cur];
    st.push(cur);
    for (int next : graph[cur]) {
        if (visited[next] == -1) ret = min(ret, dfs(next));
        else if (scc[next] == -1) ret = min(ret, visited[next]);
    }
    if (ret == visited[cur]) {
        vector<int> newScc;
        while (true) {
            int tmp = st.top();
            st.pop();
            scc[tmp] = sccCnt;
            newScc.push_back(tmp);
            if (tmp == cur) break;
        }
        sccCnt++;
        answer.push_back(newScc);
    }
    return ret;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    graph = vector<unordered_set<int>>(2 * (n + 1));
    visited = scc = vector<int>(2 * (n + 1), -1);
    while (m--) {
        int i, j;
        cin >> i >> j;
        graph[-i < 0 ? i * 2 : -i * 2 + 1].insert(j < 0 ? -j * 2 : j * 2 + 1);
        graph[-j < 0 ? j * 2 : -j * 2 + 1].insert(i < 0 ? -i * 2 : i * 2 + 1);
    }
    for (int i = 2; i < 2 * (n + 1); i++) if (visited[i] == -1) dfs(i);
    for (int i = 1; i <= n; i++) if (scc[i * 2] == scc[i * 2 + 1]) {
        cout << 0;
        return 0;
    }
    cout << "1\n";
    vector<int> result(n + 1, -1);
    for (const vector<int>& s : answer) {
        for (int cur : s) {
            if (result[cur / 2] != -1) continue;
            result[cur / 2] = cur % 2;
        }
    }
    for (int i = 1; i <= n; i++) cout << result[i] << ' ';
}