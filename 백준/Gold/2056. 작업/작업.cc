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
vector<int> sTime, indegree, wtime;
vector<vector<int>> graph;
int n;
void Input() {
    cin >> n;
    graph.resize(n + 1);
    sTime.resize(n + 1);
    wtime.resize(n + 1);
    indegree.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wtime[i];
        int pre;
        cin >> pre;
        indegree[i] += pre;
        while (pre--) {
            int p;
            cin >> p;
            graph[p].emplace_back(i);
        }
    }
}
void Solution() {
    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= n; i++) if (indegree[i] == 0) q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        ans = max(ans, sTime[cur] + wtime[cur]);
        q.pop();
        for (int next : graph[cur]) {
            if (--indegree[next] == 0) q.push(next);
            sTime[next] = max(sTime[next], sTime[cur] + wtime[cur]);
        }
    }
    cout << ans;
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}