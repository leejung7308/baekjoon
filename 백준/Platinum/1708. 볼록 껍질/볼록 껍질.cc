#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
pair<int, int> p0;
int ccw(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
	long long c = (long long)(p2.first - p1.first) * (p3.second - p2.second) - (long long)(p2.second - p1.second) * (p3.first - p2.first);
	if (c > 0) return 1;
	if (c == 0) return 0;
	if (c < 0) return -1;
}
long long dist(const pair<int, int>& p1, const pair<int, int>& p2) {
	return (long long)(p2.first - p1.first) * (p2.first - p1.first) + (long long)(p2.second - p1.second) * (p2.second - p1.second);
}
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
	int c = ccw(p0, p1, p2);
	if (c == 0) {
		return dist(p0, p1) < dist(p0, p2);
	}
	return c > 0;
}
bool cmp2(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<int> st;
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), cmp2);
	p0 = v[0];
	sort(v.begin() + 1, v.end(), cmp);
	st.push_back(0);
	st.push_back(1);
	for (int i = 2; i < n; i++) {
		while (st.size() >= 2 && ccw(v[st[st.size() - 2]], v[st[st.size() - 1]], v[i]) <= 0) st.pop_back();
		st.push_back(i);
	}
	cout << st.size();
}