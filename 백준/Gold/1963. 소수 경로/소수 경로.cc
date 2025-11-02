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
vector<bool> prime(10000, true);
string a, b;
void Init() {
    for (int i = 2; i < 5000; i++) for (int j = 2; i * j <= 9999; j++) prime[i * j] = false;
}
void Input() {
    cin >> a >> b;
    if (stoi(a) > stoi(b)) swap(a, b);
}
void Solution() {
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    vector<bool> visited(10000);
    queue<pair<string, int>> q;
    visited[stoi(a)] = true;
    q.push({ a,0 });
    while (!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cur == b) {
            cout << cnt << '\n';
            return;
        }
        for (char i = '0'; i <= '9'; i++) {
            string next = cur;
            next[3] = i;
            if (!prime[stoi(next)] || visited[stoi(next)]) continue;
            visited[stoi(next)] = true;
            q.push({ next,cnt + 1 });
        }
        for (char i = '0'; i <= '9'; i++) {
            string next = cur;
            next[2] = i;
            if (!prime[stoi(next)] || visited[stoi(next)]) continue;
            visited[stoi(next)] = true;
            q.push({ next,cnt + 1 });
        }
        for (char i = '0'; i <= '9'; i++) {
            string next = cur;
            next[1] = i;
            if (!prime[stoi(next)] || visited[stoi(next)]) continue;
            visited[stoi(next)] = true;
            q.push({ next,cnt + 1 });
        }
        for (char i = '1'; i <= '9'; i++) {
            string next = cur;
            next[0] = i;
            if (!prime[stoi(next)] || visited[stoi(next)]) continue;
            visited[stoi(next)] = true;
            q.push({ next,cnt + 1 });
        }
    }
    cout << "Impossible\n";
}
int main() {
    FAST_IO;
    int t = 1;
    cin >> t;
    while (t--) {
        Init();
        Input();
        Solution();
    }
}