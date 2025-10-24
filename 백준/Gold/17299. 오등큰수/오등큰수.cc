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
    vector<int> v(n), ans(n, -1);
    vector<int> cnt(1000001);
    stack<pii> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first < cnt[v[i]]) {
            ans[st.top().second] = v[i];
            st.pop();
        }
        st.push({ cnt[v[i]],i });
    }
    for (int i : ans) cout << i << ' ';
}