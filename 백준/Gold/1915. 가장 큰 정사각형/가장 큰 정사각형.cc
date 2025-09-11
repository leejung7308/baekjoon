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

int main() {
    FAST_IO;
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            dp[i][j] = line[j] - '0';
            cnt += dp[i][j];
        }
    }
    if (cnt == 0) {
        cout << 0;
        return 0;
    }
    if ((n == 1 || m == 1) && cnt > 0) {
        cout << 1;
        return 0;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == 0) continue;
            dp[i][j] += min({ dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j] });
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans * ans;
}