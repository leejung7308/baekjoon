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
int t, n, w;
vector<vector<int>> v;
vector<vector<pii>> c;
vector<vector<bool>> visited;
bool tryconnect(int y, int x) {
    for (const pii& d : dir) {
        int ny = y + d.first, nx = x + d.second;
        if (ny < 0 || ny >= 2) continue;
        if (nx < 0) nx = n - 1;
        if (nx >= n) nx = 0;
        if (visited[ny][nx]) continue;
        if (v[y][x] + v[ny][nx] > w) continue;
        visited[ny][nx] = true;
        if (c[ny][nx] == make_pair(-1, -1) || tryconnect(c[ny][nx].first, c[ny][nx].second)){
            c[ny][nx] = { y,x };
            c[y][x] = { ny,nx };
            return true;
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> w;
        v = vector<vector<int>>(2, vector<int>(n));
        c = vector<vector<pii>>(2, vector<pii>(n, {-1,-1}));
        for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
        for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) {
            if (c[i][j] != make_pair(-1, -1)) continue;
            visited = vector<vector<bool>>(2, vector<bool>(n));
            visited[i][j] = true;
            ans++;
            tryconnect(i, j);
        }
        cout << ans << '\n';
    }
}