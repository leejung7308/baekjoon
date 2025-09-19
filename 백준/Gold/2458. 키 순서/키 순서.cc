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

int main() {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (graph[j][k] > graph[j][i] + graph[i][k]) graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) if (graph[i][j] != INF || graph[j][i] != INF) cnt++;
        if (cnt == n - 1) ans++;
    }
    cout << ans;
}