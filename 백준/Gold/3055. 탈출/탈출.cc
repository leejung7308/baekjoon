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
struct node {
    int y, x, sec;
};
int r, c, sy, sx;
vector<pii> wpos;
vector<string> v;
vector<vector<int>> water;
void printw() {
    cout << "============\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << water[i][j] << ' ';
        cout << '\n';
    }
    cout << "============\n";
}
void wbfs() {
    vector<vector<bool>> visited(r, vector<bool>(c));
    queue<node> q;
    for (const pii& p : wpos) {
        visited[p.first][p.second] = true;
        q.push({ p.first,p.second,0 });
    }
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int sec = q.front().sec;
        q.pop();
        water[y][x] = sec;
        for (const pii& d : dir) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == '.') {
                visited[ny][nx] = true;
                q.push({ ny,nx,sec + 1 });
            }
        }
    }
}
bool hbfs() {
    vector<vector<bool>> visited(r, vector<bool>(c));
    queue<node> q;
    visited[sy][sx] = true;
    q.push({ sy,sx,0 });
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int sec = q.front().sec;
        q.pop();
        for (const pii& d : dir) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] == 'D') {
                cout << sec + 1;
                return true;
            }
            if (v[ny][nx] != 'X' && water[ny][nx] > sec + 1) {
                visited[ny][nx] = true;
                q.push({ ny,nx,sec + 1 });
            }
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> r >> c;
    water = vector<vector<int>>(r, vector<int>(c, INF));
    v.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> v[i];
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '*') wpos.push_back({ i,j });
            if (v[i][j] == 'S') sy = i, sx = j;
        }
    }
    wbfs();
    if (!hbfs()) cout << "KAKTUS";
}