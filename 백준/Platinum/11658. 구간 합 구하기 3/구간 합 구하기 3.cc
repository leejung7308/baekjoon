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
vector<vector<int>> v;
vector<vector<LL>> fenwick;
int n, m;
void update(int x, int y, int diff) {
    for (int tx = x; tx <= n; tx += tx & -tx) 
        for (int ty = y; ty <= n; ty += ty & -ty) 
            fenwick[tx][ty] += diff;
}
LL sum(int x, int y) {
    LL ret = 0;
    for (int tx = x; tx > 0; tx -= tx & -tx) 
        for (int ty = y; ty > 0; ty -= ty & -ty) 
            ret += fenwick[tx][ty];
    return ret;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    v.resize(n + 1, vector<int>(n + 1));
    fenwick.resize(n + 1, vector<LL>(n + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        cin >> v[i][j];
        update(i, j, v[i][j]);
    }
    while (m--) {
        int w;
        cin >> w;
        if (w == 0) {
            int x, y, c;
            cin >> x >> y >> c;
            update(x, y, c - v[x][y]);
            v[x][y] = c;
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            LL ans = 0;
            ans += sum(x2, y2);
            ans -= sum(x1 - 1, y2);
            ans -= sum(x2, y1 - 1);
            ans += sum(x1 - 1, y1 - 1);
            cout << ans << '\n';
        }
    }
}