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
vector<int> v;
struct node {
    int x, a, b;
};
int findroot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findroot(parent[x]);
}
int main() {
    FAST_IO;
    int n, q;
    cin >> n >> q;
    v.resize(n + 1);
    parent.resize(n + 1);
    stack<node> st;
    stack<string> ans;
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 2; i <= n; i++) cin >> v[i];
    q += n - 1;
    while (q--) {
        int x;
        cin >> x;
        if (x == 0) {
            int b;
            cin >> b;
            st.push({ x,b,v[b] });
        }
        else {
            int c, d;
            cin >> c >> d;
            st.push({ x,c,d });
        }
    }
    while (!st.empty()) {
        int x = st.top().x, a = st.top().a, b = st.top().b;
        st.pop();
        if (x == 0) parent[a] = b;
        else if (findroot(a) == findroot(b)) ans.push("YES\n");
        else ans.push("NO\n");
    }
    while (!ans.empty()) cout << ans.top(), ans.pop();
}