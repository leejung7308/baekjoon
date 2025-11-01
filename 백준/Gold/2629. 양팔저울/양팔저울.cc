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
vector<int> dp(40001);
vector<int> weight;
vector<int> marble;
int n, m;
int sum = 0;
void Input() {
    cin >> n;
    weight.resize(n);
    for (int i = 0; i < n; i++) cin >> weight[i], sum += weight[i];
    dp[0] = 1;
    cin >> m;
    marble.resize(m);
    for (int i = 0; i < m; i++) cin >> marble[i];
}
void Solution() {
    for (int i = 0; i < weight.size(); i++) {
        for (int j = sum; j >= weight[i]; j--) {
            if (dp[j - weight[i]] == 0) continue;
            dp[j] = dp[j - weight[i]] + 1;
        }
    }
    for (int i = 0; i < weight.size(); i++) {
        for (int j = weight[i]; j <= sum; j++) {
            if (dp[j] == 0) continue;
            dp[j - weight[i]] = dp[j] + 1;
        }
    }
    string ans = "";
    for (int mb : marble) dp[mb] > 0 ? ans += "Y " : ans += "N ";
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