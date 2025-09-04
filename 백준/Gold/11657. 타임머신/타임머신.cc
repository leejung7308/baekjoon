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
struct edge { int from, to, cost; };
int main() {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    vector<LL> dist(n + 1, LLINF);
    dist[1] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = { a,b,c };
    }
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int from = edges[j].from;
            int to = edges[j].to;
            int cost = edges[j].cost;
            if (dist[from] == LLINF) continue;
            dist[to] = min(dist[to], dist[from] + cost);
        }
    }
    for (int j = 0; j < m; j++) {
        int from = edges[j].from;
        int to = edges[j].to;
        int cost = edges[j].cost;
        if (dist[from] == LLINF) continue;
        if (dist[to] > dist[from] + cost) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] == LLINF) cout << "-1\n";
        else cout << dist[i] << '\n';
    }
}