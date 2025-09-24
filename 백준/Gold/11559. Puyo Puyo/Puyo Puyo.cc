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
int answer = 0;
vector<string> v(12);
vector<vector<bool>> visited(12, vector<bool>(6));
void printv() {
    for (int i = 0; i < 12; i++) cout << v[i] << '\n';
}
bool bfs(char cur, int y, int x) {
    vector<pii> eraseList;
    queue<pii> q;
    visited[y][x] = true;
    q.push({ y,x });
    eraseList.push_back({ y,x });
    int cnt = 1;
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (const pii& d : dir) {
            int ny = cy + d.first;
            int nx = cx + d.second;
            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6) continue;
            if (visited[ny][nx]) continue;
            if (v[ny][nx] != cur) continue;
            cnt++;
            eraseList.push_back({ ny,nx });
            visited[ny][nx] = true;
            q.push({ ny,nx });
        }
    }
    if (cnt >= 4) {
        for (const pii& e : eraseList) v[e.first][e.second] = '.';
        return true;
    }
    return false;
}
bool check() {
    bool ret = false;
    visited = vector<vector<bool>>(12, vector<bool>(6));
    for (int i = 11; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (v[i][j] == '.') continue;
            if (bfs(v[i][j], i, j)) ret = true;
        }
    }
    return ret;
}
void refresh() {
    bool flag;
    do {
        flag = false;
        for (int i = 11; i >= 1; i--) {
            for (int j = 0; j < 6; j++) {
                if (v[i][j] == '.' && v[i - 1][j] != '.') {
                    v[i][j] = v[i - 1][j];
                    v[i - 1][j] = '.';
                    flag = true;
                }
            }
        }
    } while (flag);
}
int main() {
    FAST_IO;
    for (int i = 0; i < 12; i++) cin >> v[i];
    while (check()) answer++, refresh();
    cout << answer;
}