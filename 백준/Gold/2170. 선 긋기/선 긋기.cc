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
int n;
LL ans = 0;
vector<pii> v;
bool cmp(const pii& a, const pii& b) {
    if (a.first < b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end(), cmp);
}
void Solution() {
    pii cur = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i].first <= cur.second) cur.second = max(cur.second, v[i].second);
        else {
            ans += cur.second - cur.first;
            cur = v[i];
        }
    }
    ans += cur.second - cur.first;
    cout << ans;
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}