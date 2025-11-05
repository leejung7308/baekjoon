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

int n, m, v, c, k;
vector<pii> things;
vector<int> dp(10001);
bool cmp(const pii& a, const pii& b) { return a.second < b.second; }
void makeThing() {
    for (int i = 1; i <= k; i *= 2) {
        things.push_back({ v * i, c * i });
        k -= i;
    }
    things.push_back({ v * k, c * k });
}
void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> v >> c >> k;
        makeThing();
    }
}
void Solution() {
    for (int i = 0; i < things.size(); i++) {
        for (int j = m; j >= things[i].first; j--) {
            dp[j] = max(dp[j], dp[j - things[i].first] + things[i].second);
        }
    }
    cout << dp[m];
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}