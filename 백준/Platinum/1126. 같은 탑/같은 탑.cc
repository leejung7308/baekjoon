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
    int n, b;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(500001, -1));
    dp[0][0] = 0;
    for (int i = 1, cur; i <= n; i++) {
        cin >> cur;
        for (int j = 0; j <= 250000; j++) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j + cur] = max(dp[i][j + cur], dp[i - 1][j] + cur);
            if (cur > j) dp[i][cur - j] = max(dp[i][cur - j], dp[i - 1][j] + cur - j);
            else dp[i][j - cur] = max(dp[i][j - cur], dp[i - 1][j]);
        }
    }
    cout << (dp[n][0] <= 0 ? -1 : dp[n][0]);
}