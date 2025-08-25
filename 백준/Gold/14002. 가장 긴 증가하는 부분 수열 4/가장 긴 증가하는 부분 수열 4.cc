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

int main() {
    FAST_IO;
    int n;
    cin >> n;
    vector<int> lis;
    vector<int> v(n), idx(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (lis.empty() || lis.back() < v[i]) lis.push_back(v[i]), idx[i] = lis.size() - 1;
        else {
            int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[index] = v[i];
            idx[i] = index;
        }
    }
    stack<int> ans;
    for (int i = lis.size() - 1; i >= 0; i--) {
        while (idx[--n] != i);
        ans.push(v[n]);
    }
    cout << lis.size() << '\n';
    while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
}