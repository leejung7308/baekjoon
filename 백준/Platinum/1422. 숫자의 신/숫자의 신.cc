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
int k, n;
vector<string> v;
bool cmp(const string& a, const string& b) {
    string A = a + b;
    string B = b + a;
    return A > B;
}
void Input() {
    cin >> k >> n;
    v.resize(k);
    for (int i = 0; i < k; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
}
void Solution() {
    int midx = -1, msize = 0;
    string ans = "";
    for (int i = 0; i < k; i++) {
        if (msize < v[i].size()) {
            msize = v[i].size();
            midx = i;
        }
    }
    for (int i = 0; i < k; i++) {
        if (i == midx) for (int j = 0; j <= n - k; j++) ans += v[i];
        else ans += v[i];
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