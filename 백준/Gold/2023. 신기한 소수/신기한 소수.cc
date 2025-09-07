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
int n;
void dfs(int cur, int cnt) {
    if (cnt == n) {
        cout << cur << '\n';
        return;
    }
    cur *= 10;
    for (int i = 0; i <= 9; i++) {
        if (cnt == 0 && i < 2) continue;
        int tmp = cur + i;
        bool isPrime = true;
        for (int j = 2; j < (int)sqrt(tmp) + 1; j++) {
            if (tmp % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) dfs(tmp, cnt + 1);
    }
}
int main() {
    FAST_IO;
    cin >> n;
    dfs(0, 0);
}