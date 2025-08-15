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
#define MAX 1000000
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first, a.second + b.second }; }
vector<int> seg(MAX * 4);
int n, m;
void update(int start, int end, int n, int idx, int diff) {
    if (idx < start || end < idx) return;
    if (seg[n] < diff) seg[n] = diff;
    if (start == end) return;
    int mid((start + end) / 2);
    update(start, mid, n * 2, idx, diff);
    update(mid + 1, end, n * 2 + 1, idx, diff);
}
int query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return -1;
    if (left <= start && end <= right) return seg[n];
    int mid((start + end) / 2);
    return max(query(start, mid, n * 2, left, right), query(mid + 1, end, n * 2 + 1, left, right));
}
int main() {
    FAST_IO;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        update(1, n, 1, i, tmp);
        if (i >= m * 2 - 1) cout << query(1, n, 1, i - m * 2 + 2, i) << ' ';
    }
}