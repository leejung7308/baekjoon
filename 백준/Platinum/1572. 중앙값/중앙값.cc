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
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
int seg[65537 * 4], n, k;
LL ans = 0;
void update(int start, int end, int N, int idx, int diff) {
    if (end < idx || idx < start) return;
    seg[N] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, N * 2, idx, diff);
    update(mid + 1, end, N * 2 + 1, idx, diff);
}
int search(int start, int end, int n, int cnt) {
    if (start == end) return start;
    int left = seg[n * 2];
    int mid = (start + end) / 2;
    if (left >= cnt) return search(start, mid, n * 2, cnt);
    if (left < cnt) return search(mid + 1, end, n * 2 + 1, cnt - left);
}
int main() {
    FAST_IO;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        update(0, 65537, 1, v[i], 1);
        if (i >= k) {
            ans += search(0, 65537, 1, (k + 1) / 2);
            update(0, 65537, 1, v[i - k + 1], -1);
        }
    }
    cout << ans;
}