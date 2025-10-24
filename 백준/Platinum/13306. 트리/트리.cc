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
vector<int> parent;
int findp(int x) {
    if (x == parent[x]) return x;
    return findp(parent[x]);
}
int main() {
    FAST_IO;
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    parent[1] = 1;
    for (int i = 2; i <= n; i++) cin >> parent[i];
    while (q > 0) {
        int x;
        cin >> x;
        if (x == 0) {
            int b;
            cin >> b;
            parent[b] = b;
        }
        else {
            q--;
            int c, d;
            cin >> c >> d;
            if (findp(c) == findp(d)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}