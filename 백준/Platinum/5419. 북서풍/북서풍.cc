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
int t, n;
vector<pii> pos;
vector<int> seg;
void update(int start, int end, int n, int idx) {
    if (idx < start || end < idx) return;
    seg[n]++;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, n * 2, idx);
    update(mid + 1, end, n * 2 + 1, idx);
}
int query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return seg[n];
    int mid = (start + end) / 2;
    return query(start, mid, n * 2, left, right) + query(mid + 1, end, n * 2 + 1, left, right);
}
bool cmp(const pii& a, const pii& b) {
    if (a.first < b.first) return true;
    else if (a.first > b.first) return false;
    else if (a.second > b.second) return true;
    else return false;
}
int main() {
    FAST_IO;
    cin >> t;
    while (t--) {
        LL ans = 0;
        cin >> n;
        pos.resize(n);
        seg = vector<int>(n * 4);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pos[i] = { x,y };
        }
        sort(pos.begin(), pos.end(), cmp);
        vector<pii> yv(n);
        for (int i = 0; i < n; i++) yv[i] = { pos[i].second,i };
        sort(yv.begin(), yv.end(), cmp);
        for (int i = 0; i < n; i++) {
            int cy = yv[i].first, idx = yv[i].second;
            ans += query(0, n - 1, 1, idx + 1, n - 1);
            update(0, n - 1, 1, idx);
        }
        cout << ans << '\n';
    }
}