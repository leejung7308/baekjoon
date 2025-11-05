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
vector<vector<int>> order(3, vector<int>(500001));
vector<int> seg(2000000, INF);
int n, ans = 0;
void update(int start, int end, int n, int idx, int diff) {
    if (idx < start || end < idx) return;
    seg[n] = min(diff, seg[n]);
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, n * 2, idx, diff);
    update(mid + 1, end, n * 2 + 1, idx, diff);
}
int query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return INF;
    if (left <= start && end <= right) return seg[n];
    int mid = (start + end) / 2;
    return min(query(start, mid, n * 2, left, right), query(mid + 1, end, n * 2 + 1, left, right));

}
void Input() {
    cin >> n;
    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) {
        int tmp;
        cin >> tmp;
        if (i == 0) order[i][j] = tmp;
        else order[i][tmp] = j;
    }
}
void Solution() {
    for (int i = 1; i <= n; i++) {
        if (query(1, n, 1, 1, order[1][order[0][i]] - 1) > order[2][order[0][i]]) ans++;
        update(1, n, 1, order[1][order[0][i]], order[2][order[0][i]]);
    }
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