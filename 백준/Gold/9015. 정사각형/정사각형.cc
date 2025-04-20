#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first + b.first,a.second + b.second };
}
pair<int, int> getdelta(const pair<int, int>& a, const pair<int, int>& b) {
	return { b.first - a.first,b.second - a.second };
}
int getarea(const pair<int, int>& delta) {
	return pow(delta.first, 2) + pow(delta.second, 2);
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		map<pair<int, int>, bool> has;
		for (int i = 0; i < n; i++) {
			pair<int, int> A;
			cin >> A.first >> A.second;
			has[A] = true;
			if (has.size() < 4) continue;
			for (const auto& h:has) {
				pair<int, int> B = h.first;
				if (A == B) continue;
				pair<int, int> delta = getdelta(A, B);
				if (getarea(delta) <= ans) continue;
				if (has.size() < 3) continue;
				pair<int, int> a, b;
				a = A + make_pair(- delta.second, delta.first);
				b = a + delta;
				if (has.find(a) != has.end() && has.find(b) != has.end()) ans = max(ans, getarea(delta));
			}
		}
		cout << ans << '\n';
	}
}