#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct line {
	int a;
	int b;
	int i;
};
bool cmp(const line& a, const line& b) {
	if (a.a < b.a) return true;
	else if (a.a == b.a) return a.b > b.b;
	else return false;
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<line> v;
	set<int> ans;
	int end = 0;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			end = max(end, b);
			v.push_back({ a,b + n,i });
		}
		else v.push_back({ a,b,i });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (v[i].a <= end && v[i].b <= end) continue;
		ans.insert(v[i].i);
		end = v[i].b;
	}
	for (const int& a : ans)cout << a << ' ';
}