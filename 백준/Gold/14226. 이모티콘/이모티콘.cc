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
struct node {
    int cur;
    int clip;
    int time;
};
int main() {
    FAST_IO;
    int s;
    cin >> s;
    queue<node> q;
    vector<vector<bool>> visited(s * 2, vector<bool>(s * 2));
    q.push({ 1,0,0 });
    while (!q.empty()) {
        node c = q.front();
        q.pop();
        int cur = c.cur;
        int clip = c.clip;
        int time = c.time;
        if (cur >= s * 2 || clip >= s * 2) continue;
        if (visited[cur][clip]) continue;
        visited[cur][clip] = true;
        if (cur == s) {
            cout << time;
            return 0;
        }
        if (clip != cur) q.push({ cur,cur,time + 1 });
        if (clip != 0) q.push({ cur + clip,clip,time + 1 });
        if (cur > 1) q.push({ cur - 1,clip,time + 1 });
    }
}