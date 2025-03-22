#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) return a > b;
	else return (a + b) > (b + a);
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	string ans;
	for (int i = 0; i < n; i++) ans += v[i];
	if (ans[0] == '0') cout << 0;
	else cout << ans;
}