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
vector<vector<int>> opinion;
vector<int> has;
vector<bool> visited;
int n, m;
bool tryconnect(int who) {
    for (int x : opinion[who]) {
        if (visited[x]) continue;
        visited[x] = true;
        if (has[x] == 0) {
            has[x] = who;
            return true;
        }
        else {
            if (tryconnect(has[x])) {
                has[x] = who;
                return true;
            }
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    opinion.resize(n + 1);
    has.resize(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        opinion[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        visited = vector<bool>(n + 1);
        if (tryconnect(i)) ans++;
    }
    cout << ans;
}