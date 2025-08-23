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
int n;
bool isodd = false;
vector<bool> prime(2000, true);
vector<int> ans, owner, v;
vector<bool> visited;
void printv(vector<int> v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << '\n';
}
bool tryconnect(int x) {
    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        if (!prime[v[i] + v[x]]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        if (owner[i] == -1 || tryconnect(owner[i])) {
            owner[i] = x;
            return true;
        }
    }
    return false;
}
int main() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < 2000; i++) for (int j = 2; j < i; j++) if (i % j == 0) prime[i] = false;
    FAST_IO;
    cin >> n;
    v = vector<int>(n);
    owner = vector<int>(n, -1);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) even++;
        else odd++;
    }
    if (odd != even) {
        cout << -1;
        return 0;
    }
    if (v[0] % 2 == 1) isodd = true;
    for (int i = 1; i < n; i++) {
        visited = vector<bool>(n);
        if (isodd && v[i] % 2 == 0) continue;
        else if (!isodd && v[i] % 2 == 1) continue;
        if (!tryconnect(i)) {
            cout << "-1";
            return 0;
        }
    }

    for (int i = 1; i < n; i++) {
        visited = vector<bool>(n);
        if (!prime[v[0] + v[i]]) continue;
        if (visited[i]) continue;
        visited[i] = true;
        if (owner[i] == -1 || tryconnect(owner[i])) {
            ans.push_back(v[i]);
            owner[i] = -1;
        }
    }
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << ' ';
    if (ans.size() == 0) cout << -1;
}