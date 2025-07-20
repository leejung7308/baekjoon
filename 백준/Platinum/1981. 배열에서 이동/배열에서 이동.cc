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
DIR;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<vector<int>> v;
vector<vector<bool>> visited;
int n, MAX = -1, MIN = 300;
bool bfs(int mid) {
    queue<pii> q;
    for (int i = MIN; i <= MAX; i++) {
        visited = vector<vector<bool>>(n, vector<bool>(n, true));
        for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) if (i <= v[j][k] && v[j][k] <= i + mid) visited[j][k] = false;
        q.push({ 0,0 });
        while (!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            if (visited[cy][cx]) continue;
            visited[cy][cx] = true;
            if (cy == n - 1 && cx == n - 1) return true;
            for (const pii& d : dir) {
                int ny = cy + d.first;
                int nx = cx + d.second;
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                q.push({ ny,nx });
            }
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> v[i][j];
        MAX = max(MAX, v[i][j]);
        MIN = min(MIN, v[i][j]);
    }
    int s = 0, e = MAX - MIN, mid;
    while (s <= e) {
        mid = (s + e) / 2;
        if (bfs(mid)) e = mid - 1;
        else s = mid + 1;
    }
    cout << e + 1;
}