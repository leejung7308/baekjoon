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
struct edge {
    int a, b, c;
};
int n, m, sum;
vector<edge> edges;
vector<int> parent;
int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
bool Union(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    parent[b] = a;
    return true;
}
void Input() {
    cin >> n >> m;
    if (n == 0 && m == 0) exit(0);
    parent = vector<int>(n);
    edges = vector<edge>(m);
    sum = 0;
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) cin >> edges[i].a >> edges[i].b >> edges[i].c, sum += edges[i].c;
}
void Solution() {
    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) { return a.c < b.c; });
    int cnt = 0;
    int total = 0;
    for (auto& [a, b, c] : edges) {
        if (Union(a, b)) ++cnt, total += c;
        if (cnt == n - 1) break;
    }
    cout << sum - total << '\n';
}
int main() {
    FAST_IO;
    int t = 1;
    while (t++) {
        Input();
        Solution();
    }
}