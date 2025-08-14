#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
#define DIR8 const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int, int>
#define MAX 65536
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<int> seg(MAX * 4, 0), v;
void update(int start, int end, int n, int idx, int diff) {
    if (idx < start || end < idx) return;
    seg[n] += diff;
    if (start == end) return;
    int mid((start + end) / 2);
    update(start, mid, n * 2, idx, diff);
    update(mid + 1, end, n * 2 + 1, idx, diff);
}
int query(int start, int end, int n, int k) {
    if (start == end) return end;
    int mid((start + end) / 2);
    if (seg[n * 2] >= k) return query(start, mid, n * 2, k);
    if (seg[n * 2] < k) return query(mid + 1, end, n * 2 + 1, k - seg[n * 2]);
}
int main() {
    FAST_IO;
    int n, k;
    LL ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        update(0, MAX, 1, tmp, 1);
        if (i >= k) {
            ans += query(0, MAX, 1, (k + 1) / 2);
            update(0, MAX, 1, v[i - k], -1);
        }
    }
    cout << ans;
}