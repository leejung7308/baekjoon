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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(s.size() + 1, 0);
    if (s[0] == '0') {
        cout << 0;
        return 0;
    }
    dp[0] = dp[1] = 1;
    s = ' ' + s;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '0' && s[i - 1] > '2') {
            cout << 0;
            return 0;
        }
        if (s[i] != '0') {
            dp[i] += dp[i - 1];
            dp[i] %= 1000000;
        }
        if ((s[i] <= '6' && s[i] >= '0' && s[i - 1] == '2') || s[i - 1] == '1') {
            dp[i] += dp[i - 2];
            dp[i] %= 1000000;
        }
    }
    cout << dp[n];
}