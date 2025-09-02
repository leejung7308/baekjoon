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
int t, c;
pii s, e;
vector<pii> convenient;
bool bfs() {
    vector<bool> visited(c);
    queue<int> q;
    for (int i = 0; i < c; i++) {
        if (abs(convenient[i].first - s.first) + abs(convenient[i].second - s.second) <= 1000) {
            visited[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        pii cur = convenient[q.front()];
        q.pop();
        if (abs(e.first - cur.first) + abs(e.second - cur.second) <= 1000) return true;
        for (int i = 0; i < c; i++) {
            if (visited[i]) continue;
            if (abs(convenient[i].first - cur.first) + abs(convenient[i].second - cur.second) > 1000) continue;
            visited[i] = true;
            q.push(i);
        }
    }
    return false;
}
int main() {
    FAST_IO;
    cin >> t;
    while (t--) {
        cin >> c;
        convenient = vector<pii>(c);
        cin >> s.first >> s.second;
        for (int i = 0; i < c; i++) cin >> convenient[i].first >> convenient[i].second;
        cin >> e.first >> e.second;
        if (abs(e.first - s.first) + abs(e.second - s.second) <= 1000) {
            cout << "happy\n";
            continue;
        }
        if (bfs()) cout << "happy\n";
        else cout << "sad\n";
    }
}