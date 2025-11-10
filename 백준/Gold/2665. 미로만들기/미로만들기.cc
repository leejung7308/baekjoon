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
struct node {
    int y, x, cnt;
};
DIR;
int ans = INF;
int n;
vector<string> v;
void Solution() {
    vector<vector<int>> visited(n, vector<int>(n, INF));
    queue<node> q;
    visited[0][0] = 0;
    q.push({ 0,0,0 });
    while (!q.empty()) {
        int cy = q.front().y;
        int cx = q.front().x;
        int cnt = q.front().cnt;
        q.pop();
        if (cy == n - 1 && cx == n - 1) {
            ans = min(ans, cnt);
        }
        for (const pii& d : dir) {
            int ny = cy + d.first;
            int nx = cx + d.second;
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (v[ny][nx] == '1' && visited[ny][nx] > cnt) {
                visited[ny][nx] = cnt;
                q.push({ ny,nx,cnt });
            }
            else if (v[ny][nx] == '0' && visited[ny][nx] > cnt + 1) {
                visited[ny][nx] = cnt + 1;
                q.push({ ny,nx,cnt + 1 });
            }
        }
    }
    cout << ans;
}
void Input() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}