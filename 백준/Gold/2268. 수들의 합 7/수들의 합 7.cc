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
vector<long long> fenwick, v;
int n, m;
void update(int idx, long long diff) {
    while (idx <= n) {
        fenwick[idx] += diff;
        idx += idx & -idx;
    }
}
long long sum(int idx) {
    long long ret = 0;
    while (idx > 0) {
        ret += fenwick[idx];
        idx -= idx & -idx;
    }
    return ret;
}
int main() {
    FAST_IO;
    cin >> n >> m;
    fenwick.resize(n + 1);
    v.resize(n + 1);
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            if(a > b) swap(a, b);
            cout << sum(b) - sum(a - 1) << '\n';
        }
        else {
            long long diff = b - v[a];
            v[a] = b;
            update(a, diff);
        }
    }
}