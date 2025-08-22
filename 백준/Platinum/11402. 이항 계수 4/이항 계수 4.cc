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
    LL n, k, m;
    cin >> n >> k >> m;
    vector<vector<int>> combine(m + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; i++) for (int j = 0; j <= i; j++) combine[i][j] = !i || !j ? 1 : (combine[i - 1][j] + combine[i - 1][j - 1]) % m;
    LL ans = 1;
    while (n || k) {
        ans = (ans * combine[n % m][k % m]) % m;
        n /= m, k /= m;
    }
    cout << ans;
}