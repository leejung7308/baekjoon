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
LL op(LL a, LL b) {
    if (a == 1) {
        if (b == 1) return 2;
        else return 1;
    }
    else if (b == 1) return a + 1;
    if (b == 0 || a % b == 0) return -1;
    long long remainder = a % b;
    if (remainder == 1) return (a * (b - 1) + 1) / b;
    if (b % remainder == 1) return (a * (b / remainder) + 1) / b;
    LL tmp = op(remainder, b % remainder);
    if (tmp == -1) return -1;
    return ((a * ((b * tmp - 1) / remainder)) + 1) / b;
}
int main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int k, c;
        cin >> k >> c;
        LL ans = op(k, c);
        if (ans == -1 || ans >= INF) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';
    }
}