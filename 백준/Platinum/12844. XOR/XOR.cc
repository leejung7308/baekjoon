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
int seg[2000000], lazy[2000000];
int n, m;
void lazyupdate(int start, int end, int n) {
    if ((end - start + 1) % 2 == 1)seg[n] ^= lazy[n];
    lazy[n * 2] ^= lazy[n];
    lazy[n * 2 + 1] ^= lazy[n];
    lazy[n] = 0;
}
void update(int start, int end, int n, int left, int  right, int diff) {
    if (lazy[n] != 0) {
        if (start == end) {
            seg[n] ^= lazy[n];
            lazy[n] = 0;
        }
        else lazyupdate(start, end, n);
    }
    if (end < left || right < start) return;
    if (left <= start && end <= right) {
        if ((end - start + 1) % 2 == 1) seg[n] ^= diff;
        if (start != end) lazy[n * 2] ^= diff, lazy[n * 2 + 1] ^= diff;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, n * 2, left, right, diff);
    update(mid + 1, end, n * 2 + 1, left, right, diff);
    seg[n] = seg[n * 2] ^ seg[n * 2 + 1];
}
int query(int start, int end, int n, int left, int right) {
    if (end < left || right < start) return 0;
    int mid = (start + end) / 2;
    if (lazy[n] != 0) {
        if (start == end) {
            seg[n] ^= lazy[n];
            lazy[n] = 0;
        }
        else lazyupdate(start, end, n);
    }
    if (left <= start && end <= right) return seg[n];
    return query(start, mid, n * 2, left, right) ^ query(mid + 1, end, n * 2 + 1, left, right);
}
int main() {
    FAST_IO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        update(0, n - 1, 1, i, i, tmp);
    }
    cin >> m;
    while (m--) {
        int op, i, j;
        cin >> op >> i >> j;
        if (op == 1) {
            int k;
            cin >> k;
            update(0, n - 1, 1, i, j, k);
        }
        else cout << query(0, n - 1, 1, i, j) << '\n';
    }
}