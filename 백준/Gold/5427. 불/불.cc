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
DIR;
struct node { int y, x, cur; };
int t, w, h;
vector<vector<int>> fire;
vector<string> v;
vector<pii> pos;
pii start;
void firebfs() {
    if (pos.size() == 0) return;
    vector<vector<bool>> visited(h, vector<bool>(w));
    queue<node> q;
    for (const pii& p : pos) {
        visited[p.first][p.second] = true;
        q.push({ p.first,p.second,0 });
    }
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cur = q.front().cur;
        q.pop();
        fire[y][x] = cur;
        for (const pii& d : dir) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == '#') continue;
            visited[ny][nx] = true;
            q.push({ ny,nx,cur + 1 });
        }
    }
}
int sgbfs() {
    vector<vector<bool>> visited(h, vector<bool>(w));
    queue<node> q;
    visited[start.first][start.second] = true;
    q.push({ start.first, start.second, 0 });
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cur = q.front().cur;
        q.pop();
        for (const pii& d : dir) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) return cur + 1;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == '#') continue;
            if (fire[ny][nx] <= cur + 1) continue;
            visited[ny][nx] = true;
            q.push({ ny,nx,cur + 1 });
        }
    }
    return 0;
}
int main() {
    FAST_IO;
    cin >> t;
    while (t--) {
        cin >> w >> h;
        fire = vector<vector<int>>(h, vector<int>(w, INF));
        v = vector<string>(h);
        pos.clear();
        for (int i = 0; i < h; i++) {
            cin >> v[i];
            for (int j = 0; j < w; j++) {
                if (v[i][j] == '*') pos.push_back({ i,j });
                else if (v[i][j] == '@') start = { i,j };
            }
        }
        firebfs();
        int ans = sgbfs();
        ans == 0 ? cout << "IMPOSSIBLE\n" : cout << ans << '\n';
    }
}