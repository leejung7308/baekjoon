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
vector<vector<int>> seg(400000, vector<int>());
vector<int> v;
int k;
vector<int> update(int start, int end, int n) {
    if (start == end) return seg[n] = { v[start] };
    int mid = (start + end) / 2;
    vector<int> l = update(start, mid, n * 2);
    vector<int> r = update(mid + 1, end, n * 2 + 1);
    int lp = 0, rp = 0;
    while (!(lp == l.size() && rp == r.size())) {
        if (lp == l.size()) seg[n].push_back(r[rp++]);
        else if (rp == r.size()) seg[n].push_back(l[lp++]);
        else if (l[lp] > r[rp]) seg[n].push_back(r[rp++]);
        else seg[n].push_back(l[lp++]);
    }
    return seg[n];
}
int query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return seg[n].end() - upper_bound(seg[n].begin(), seg[n].end(), k);
    int mid = (start + end) / 2;
    return query(start, mid, n * 2, left, right) + query(mid + 1, end, n * 2 + 1, left, right);
}
int main() {
    FAST_IO;
    int n, la = 0;
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    update(1, n, 1);
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        int i, j;
        i = a ^ la;
        j = b ^ la;
        k = c ^ la;
        cout << (la = query(1, n, 1, i, j)) << '\n';
    }
}