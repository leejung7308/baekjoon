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
int n;
int seg[4000000];
void update(int start, int end, int n, int idx) {
    if (idx < start || end < idx) return;
    seg[n]++;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, n * 2, idx);
    update(mid + 1, end, n * 2 + 1, idx);
}
int sum(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return seg[n];
    int mid = (start + end) / 2;
    return sum(start, mid, n * 2, left, right) + sum(mid + 1, end, n * 2 + 1, left, right);
}
int main() {
    FAST_IO;
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ans += sum(1, n, 1, tmp + 1, n);
        update(1, n, 1, tmp);
    }
    cout << ans;
}