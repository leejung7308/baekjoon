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
vector<int> pick;
vector<bool> visited;
vector<vector<int>> want;
int n, m, k1, k2, i, j;
int Solution();
bool tryconnect(int x) {
    for (int w : want[x]) {
        if (visited[w]) continue;
        visited[w] = true;
        if (pick[w] == 0 || tryconnect(pick[w])) {
            pick[w] = x;
            return true;
        }
    }
    return false;
}
void Input() {
    int cnt1 = 0, cnt2 = 0;
    cin >> n >> m >> k1 >> k2;
    want = vector<vector<int>>(n + 1);
    pick = vector<int>(m + 1);
    while (k1--) {
        cin >> i >> j;
        want[i].push_back(j);
    }
    cnt1 = Solution();
    want = vector<vector<int>>(n + 1);
    pick = vector<int>(m + 1);
    while (k2--) {
        cin >> i >> j;
        want[i].push_back(j);
    }
    cnt2 = Solution();
    if (cnt1 < cnt2) cout << "네 다음 힐딱이";
    else cout << "그만 알아보자";
}
int Solution() {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        visited = vector<bool>(m + 1);
        if (tryconnect(i)) ret++;
    }
    return ret;
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
    }
}