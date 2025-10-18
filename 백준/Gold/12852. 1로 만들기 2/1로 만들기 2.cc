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
vector<vector<int>> dp(1000001);
vector<int> dfs(int x) {
    if (x == 1) return { 1 };
    if (dp[x].size() != 0) return dp[x];
    vector<int> tmp;
    if (x % 3 == 0) {
        dp[x] = dfs(x / 3);
    }
    if (x % 2 == 0) {
        tmp = dfs(x / 2);
        if (dp[x].size() == 0 || (dp[x].size() != 0 && tmp.size() < dp[x].size())) {
            dp[x] = tmp;
        }
    }
    if (x - 1 >= 1) {
        tmp = dfs(x - 1);
        if (dp[x].size() == 0 || (dp[x].size() != 0 && tmp.size() < dp[x].size())) {
            dp[x] = tmp;
        }
    }
    dp[x].emplace_back(x);
    return dp[x];
}
int main() {
    FAST_IO;
    int n;
    cin >> n;
    vector<int> ans = dfs(n);
    cout << ans.size() - 1 << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
}