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
vector<int> weight;
vector<bool> visited;
vector<int> sum1, sum2;
int n, c, ans = 0;
void dfs(int idx, int end, int sum, vector<int>& v) {
    v.push_back(sum);
    for (int i = idx; i < end; i++) {
        if (visited[i]) continue;
        if (sum + weight[i] > c) continue;
        visited[i] = true;
        dfs(i + 1, end, sum + weight[i], v);
        visited[i] = false;
    }
}
int main() {
    FAST_IO;
    cin >> n >> c;
    weight.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    dfs(0, n / 2, 0, sum1);
    dfs(n / 2, n, 0, sum2);
    for (int i : sum1) for (int j : sum2) if (i + j <= c) ans++;
    cout << ans;
}