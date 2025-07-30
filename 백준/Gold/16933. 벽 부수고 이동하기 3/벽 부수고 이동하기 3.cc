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
DIR;
struct node {
    int y, x, used, cnt;
    bool isNight;
};
int n, m, k;
bool visited[1000][1000][2][11];
vector<string> v;
bool bfs() {
    queue<node> q;
    visited[0][0][0][0] = true;
    q.push({ 0,0,0,1,false });
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int used = q.front().used;
        int cnt = q.front().cnt;
        bool isNight = q.front().isNight;
        q.pop();
        if (y == n - 1 && x == m - 1) {
            cout << cnt;
            return true;
        }
        for (const pii& d : dir) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (v[ny][nx] == '0') {
                if (visited[ny][nx][!isNight][used]) continue;
                visited[ny][nx][!isNight][used] = true;
                q.push({ ny,nx,used,cnt + 1,!isNight });
            }
            else if (v[ny][nx] == '1') {
                if (used == k) continue;
                if (visited[ny][nx][!isNight][used + 1]) continue;
                if (isNight) q.push({ y,x,used,cnt + 1,!isNight });
                else {
                    visited[ny][nx][!isNight][used + 1] = true;
                    q.push({ ny,nx,used + 1,cnt + 1,!isNight });
                }
            }
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n >> m >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (!bfs()) cout << -1;
}