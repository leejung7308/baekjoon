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
vector<vector<LL>> comb(201, vector<LL>(201, 1));
void construct() {
    for (int i = 2; i <= 200; i++) {
        for (int j = 1; j <= i - 1; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= INF) comb[i][j] = INF;
            //cout << comb[i][j] << ' ';
        }
        //cout << '\n';
    }
}
void stringbuild(int n, int m, int k) {
    if (n == 0 && m == 0) return;
    if (comb[n + m - 1][m] >= k && n > 0) {
        cout << 'a';
        stringbuild(n - 1, m, k);
    }
    else if (m > 0) {
        cout << 'z';
        stringbuild(n, m - 1, k - comb[n + m - 1][m]);
    }
}
int main() {
    FAST_IO;
    construct();
    int n, m, k;
    cin >> n >> m >> k;
    if (comb[n + m][m] < k) {
        cout << -1;
        return 0;
    }
    stringbuild(n, m, k);
}