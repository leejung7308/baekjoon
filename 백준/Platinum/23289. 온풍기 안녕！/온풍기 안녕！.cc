#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
DIR;
struct fan { int x, y, d; };
struct wind { int x, y, t; };
const vector<vector<pii>> fdir = {
    {{0,1},{1,1},{-1,1}},
    {{0,-1},{1,-1},{-1,-1}},
    {{-1,0},{-1,1},{-1,-1}},
    {{1,0},{1,1},{1,-1}}
};
int r, c, k, w;
vector<vector<int>> v;
map<pii, pair<bool,bool>> walls;
vector<fan> fans;
vector<pii> check;
void printv() {
    cout << "==========================\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
    cout << "==========================\n";
}
void init() {
    cin >> r >> c >> k;
    v.resize(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == 0) continue;
            if (v[i][j] == 5) check.push_back({ i,j });
            else fans.push_back({ i,j,v[i][j] - 1 });
            v[i][j] = 0;
        }
    }
    cin >> w;
    for (int i = 0; i < w; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == 0) walls[{x - 1, y - 1}].first = true;
        else walls[{x - 1, y - 1}].second = true;
    }
}
bool checkWall(int d, int idx, int x, int y) {
    switch (d) {
    case 0:
        switch (idx) {
        case 0:
            if (walls.find({ x,y }) != walls.end() && walls[{x, y}].second) return false;
            else return true;
        case 1:
            if ((walls.find({ x + 1,y }) != walls.end() && walls[{x + 1, y}].first) || (walls.find({ x + 1,y }) != walls.end() && walls[{x + 1, y}].second)) return false;
            else return true;
        case 2:
            if ((walls.find({ x,y }) != walls.end() && walls[{x, y}].first) || (walls.find({ x - 1,y }) != walls.end() && walls[{x - 1, y}].second)) return false;
            else return true;
        }
        break;
    case 1:
        switch (idx) {
        case 0:
            if (walls.find({ x,y - 1 }) != walls.end() && walls[{x, y - 1}].second) return false;
            else return true;
        case 1:
            if ((walls.find({ x + 1,y }) != walls.end() && walls[{x + 1, y}].first) || (walls.find({ x + 1,y - 1 }) != walls.end() && walls[{x + 1, y - 1}].second)) return false;
            else return true;
        case 2:
            if ((walls.find({ x,y }) != walls.end() && walls[{x, y}].first) || (walls.find({ x - 1,y - 1 }) != walls.end() && walls[{x - 1, y - 1}].second)) return false;
            else return true;
        }
        break;
    case 2:
        switch (idx) {
        case 0:
            if (walls.find({ x,y }) != walls.end() && walls[{x, y}].first) return false;
            else return true;
        case 1:
            if ((walls.find({ x,y + 1 }) != walls.end() && walls[{x, y + 1}].first) || (walls.find({ x,y }) != walls.end() && walls[{x, y}].second)) return false;
            else return true;
        case 2:
            if (walls.find({ x,y - 1 }) != walls.end() && (walls[{x, y - 1}].first || walls[{x, y - 1}].second)) return false;
            else return true;
        }
        break;
    case 3:
        switch (idx) {
        case 0:
            if (walls.find({ x + 1,y }) != walls.end() && walls[{x + 1, y}].first) return false;
            else return true;
        case 1:
            if ((walls.find({ x + 1,y + 1 }) != walls.end() && walls[{x + 1, y + 1}].first) || (walls.find({ x,y }) != walls.end() && walls[{x, y}].second)) return false;
            else return true;
        case 2:
            if ((walls.find({ x + 1,y - 1}) != walls.end() && walls[{x + 1, y - 1}].first) || (walls.find({ x,y - 1 }) != walls.end() && walls[{x, y - 1}].second)) return false;
            else return true;
        }
        break;
    }
}
void blow() {
    for (const fan& f : fans) {
        vector<vector<bool>> visited(r, vector<bool>(c));
        queue<wind> q;
        visited[f.x + fdir[f.d][0].first][f.y + fdir[f.d][0].second] = true;
        q.push({ f.x + fdir[f.d][0].first,f.y + fdir[f.d][0].second,5 });
        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int t = q.front().t;
            q.pop();
            v[x][y] += t;
            if (t == 1) continue;
            for (int i = 0; i < 3; i++) {
                pii d = fdir[f.d][i];
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (visited[nx][ny]) continue;
                bool canSend = checkWall(f.d, i, x, y);
                if (canSend) {
                    visited[nx][ny] = true;
                    q.push({ nx,ny,t - 1, });
                }
            }
        }
    }
}
void distribute() {
    queue<wind> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int d = 0; d < 4; d++) {
                const pii& dr = dir[d];
                int nx = i + dr.first;
                int ny = j + dr.second;
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (checkWall(d, 0, i, j)) {
                    if (v[i][j] < v[nx][ny]) continue;
                    int delta = (v[i][j] - v[nx][ny]) / 4;
                    q.push({ i,j,-delta });
                    q.push({ nx,ny,delta });
                }
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int delta = q.front().t;
        q.pop();
        v[x][y] += delta;
        if (v[x][y] < 0) v[x][y] = 0;
    }
}
void decrease() {
    for (int i = 0; i < c; i++) {
        if(v[0][i] > 0) v[0][i]--;
        if(v[r-1][i] > 0) v[r - 1][i]--;
    }
    for (int i = 1; i < r - 1; i++) {
        if(v[i][0]) v[i][0]--;
        if(v[i][c-1]) v[i][c - 1]--;
    }
}
bool checkTemperature() {
    for (const pii& c : check) if (v[c.first][c.second] < k) return false;
    return true;
}
int main() {
    FAST_IO;
    int ans = 0;
    init();
    while(ans < 101){
        blow();
        distribute();
        decrease();
        ans++;
        if (checkTemperature()) break;
    }
    cout << ans;
}