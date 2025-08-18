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
int n, m;
vector<string> v;
void printv(const vector<string>& v) {
    cout << "==================\n";
    for (const string& s : v) cout << s << '\n';
    cout << "==================\n";
}
vector<string> roll(vector<string> v, int d) {
    int ry, rx;
    int by, bx;
    ry = rx = by = bx = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (v[i][j] == 'R') ry = i, rx = j;
        else if (v[i][j] == 'B') by = i, bx = j;
    }
    if (ry == by && rx == bx) return v;
    queue<pii> q;
    if (d == 0 && ry == by) {
        if (rx > bx) q.push({ ry,rx }), q.push({ by,bx });
        else q.push({ by,bx }), q.push({ ry,rx });
    }
    else if (d == 1 && rx == bx) {
        if (ry > by) q.push({ ry,rx }), q.push({ by,bx });
        else q.push({ by,bx }), q.push({ ry,rx });
    }
    else if (d == 2 && ry == by) {
        if (rx < bx) q.push({ ry,rx }), q.push({ by,bx });
        else q.push({ by,bx }), q.push({ ry,rx });
    }
    else if (d == 3 && rx == bx) {
        if (ry < by) q.push({ ry,rx }), q.push({ by,bx });
        else q.push({ by,bx }), q.push({ ry,rx });
    }
    else q.push({ ry,rx }), q.push({ by,bx });
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int ny = y + dir[d].first;
        int nx = x + dir[d].second;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (v[ny][nx] == 'O') v[y][x] = '.';
        else if (v[ny][nx] == '.') {
            v[ny][nx] = v[y][x];
            v[y][x] = '.';
            q.push({ ny,nx });
        }
    }
    //printv(v);
    return v;
}
bool check(const vector<string>& v) {
    bool rflag = false, bflag = false;
    for (const string& s : v) {
        for (char c : s) {
            if (c == 'R') rflag = true;
            else if (c == 'B') bflag = true;
        }
    }
    return !rflag && bflag;
}
bool dfs(const vector<string>& v, int cnt, int prev) {
    if (cnt == 10) return false;
    for (int i = 0; i < 4; i++) {
        if (prev == i) continue;
        vector<string> next = roll(v, i);
        if (check(next)) return true;
        if (dfs(next, cnt + 1, i)) return true;
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (dfs(v, 0, -1)) cout << 1;
    else cout << 0;
}