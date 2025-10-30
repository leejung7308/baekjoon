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
int A, B, C;
bool visited[201][201][201];
vector<int> ans;
void bfs() {
    queue<tuple<int, int, int>> q;
    q.push({ 0,0,C });
    while (!q.empty()) {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();
        if (visited[a][b][c]) continue;
        visited[a][b][c] = true;
        if (a == 0) ans.push_back(c);
        if (a + b > B) q.push({ a + b - B,B,c });
        else q.push({ 0,a + b,c });
        if (a + c > C) q.push({ a + c - C,b,C });
        else q.push({ 0,b,a + c });
        if (b + a > A) q.push({ A,b + a - A,c });
        else q.push({ b + a,0,c });
        if (b + c > C) q.push({ a,b + c - C,C });
        else q.push({ a,0,b + c });
        if (c + a > A) q.push({ A,b,c + a - A });
        else q.push({ c + a,b,0 });
        if (c + b > B) q.push({ a,B,c + b - B });
        else q.push({ a,c + b,0 });
    }
}
void Solution() {
    cin >> A >> B >> C;
    bfs();
    sort(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Solution();
    }
}