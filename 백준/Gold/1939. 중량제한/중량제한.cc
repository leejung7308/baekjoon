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
int n, m, s, e;
struct edge {
    int from, to, cost;
};
vector<edge> edges;
vector<int> parent;
bool cmp(const edge& a, const edge& b) { return a.cost > b.cost; }
void Input() {
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({ a,b,c });
    }
    cin >> s >> e;
    sort(edges.begin(), edges.end(), cmp);
}
int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}
bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    parent[b] = a;
    return true;
}
void Solution() {
    int ans = INF;
    for (edge ed : edges) {
        if (Union(ed.from, ed.to)) ans = min(ans, ed.cost);
        if (Find(s)==Find(e)) break;
    }
    cout << ans;
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}