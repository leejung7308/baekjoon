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
int t, n, m;
vector<int> v;
vector<vector<int>> dp;
int bitcount(int x) {
    int ret = 0;
    int bit = 1;
    while (x != 0) {
        if (bit & x) ret++;
        x >>= 1;
    }
    return ret;
}
int main() {
    FAST_IO;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v = vector<int>(n);
        dp = vector<vector<int>>(n, vector<int>(pow(2, m)));
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            int bit = 0;
            for (int j = 0; j < m; j++) {
                if (tmp[j] == '.') bit <<= 1;
                else bit <<= 1, bit++;
            }
            v[i] = bit;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < pow(2, m); j++) {
                if (v[i] & j) continue;
                int left = j << 1, right = j >> 1;
                if (j & left || j & right) continue;
                int cnt = bitcount(j);
                if (i == 0) {
                    dp[i][j] = cnt;
                    continue;
                }
                for (int k = 0; k < pow(2, m); k++) {
                    if (k & left || k & right) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
                }
            }
        }
        for (int i = 0; i < pow(2, m); i++) ans = max(ans, dp[n - 1][i]);
        cout << ans << '\n';
    }
}