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
int n, m;
vector<vector<int>> hope;
vector<int> owner;
vector<bool> visited;
bool tryconnect(int i) {
    for (int barn : hope[i]) {
        if (visited[barn]) continue;
        visited[barn] = true;
        if (owner[barn] == 0) {
            owner[barn] = i;
            return true;
        }
        else if (tryconnect(owner[barn])) {
            owner[barn] = i;
            return true;
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    hope.resize(n + 1);
    owner.resize(m + 1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        hope[i].resize(t);
        for (int j = 0; j < t; j++) cin >> hope[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        visited = vector<bool>(m + 1, false);
        if (tryconnect(i)) ans++;
    }
    cout << ans;
}