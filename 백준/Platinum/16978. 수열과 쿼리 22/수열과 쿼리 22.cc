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
struct q1 { int i, v; };
struct q2 { int k, i, j, idx; };
int n, m;
LL seg[400000];
int v[100001];
vector<LL> ans;
vector<q1> q1v;
vector<q2> q2v;
bool cmp(const q2& a, const q2& b) { return a.k < b.k; }
void update(int start, int end, int n, int idx, int diff) {
    if (idx < start || end < idx) return;
    seg[n] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, n * 2, idx, diff);
    update(mid + 1, end, n * 2 + 1, idx, diff);
}
LL query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return seg[n];
    int mid = (start + end) / 2;
    return query(start, mid, n * 2, left, right) + query(mid + 1, end, n * 2 + 1, left, right);
}
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        update(1, n, 1, i, v[i]);
    }
    cin >> m;
    int cnt = 0;
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            q1v.push_back({ i,v });
        }
        else {
            int k, i, j;
            cin >> k >> i >> j;
            q2v.push_back({ k,i,j,cnt++ });
        }
    }
}
void Solution() {
    sort(q2v.begin(), q2v.end(), cmp);
    ans.resize(q2v.size());
    int cur = 0;
    for (const q2& q : q2v) {
        int k = q.k;
        int i = q.i;
        int j = q.j;
        int idx = q.idx;
        for (; cur < k; cur++) {
            int diff = q1v[cur].v - v[q1v[cur].i];
            v[q1v[cur].i] = q1v[cur].v;
            update(1, n, 1, q1v[cur].i, diff);
        }
        ans[idx] = query(1, n, 1, i, j);
    }
    for(int i=0;i<ans.size();i++) cout << ans[i] << '\n';
}
int main() {
    FAST_IO;
    int t = 1;
    while (t--) {
        Input();
        Solution();
    }
}