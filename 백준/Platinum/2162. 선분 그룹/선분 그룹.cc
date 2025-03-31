#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> parent(1);
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	long long c = (long long)(p2.first - p1.first) * (p3.second - p2.second) - (long long)(p3.first - p2.first) * (p2.second - p1.second);
	if (c < 0) return -1;
	if (c == 0) return 0;
	if (c > 0) return 1;
}
bool isCross(pair<int, int> la1, pair<int, int>la2, pair<int, int>lb1, pair<int, int>lb2) {
	int c1 = ccw(la1, la2, lb1) * ccw(la1, la2, lb2);
	int c2 = ccw(lb1, lb2, la1) * ccw(lb1, lb2, la2);
	if (c1 == 0 && c2 == 0) {
		if (max(la1, la2) >= max(lb1, lb2) && min(la1, la2) <= max(lb1, lb2)) return true;
		if (max(la1, la2) <= max(lb1, lb2) && max(la1, la2) >= min(lb1, lb2)) return true;
		return false;
	}
	if (c1 <= 0 && c2 <= 0) return true;
	return false;
}
int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}
void uni(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}
int main() {
	FAST_IO;
	int n, group = 0;
	unordered_map<int, vector<pair<pair<int, int>, pair<int, int>>>> v;
	cin >> n;
	while (n--) {
		pair<int, int> a, b;
		int cur = -1;
		cin >> a.first >> a.second >> b.first >> b.second;
		if (v.size() == 0) {
			v[group].push_back({ a, b });
			continue;
		}
		for (auto& p : v) {
			for (auto& line : p.second) {
				if (isCross(line.first, line.second, a, b)) {
					if (cur != -1) {
						uni(p.first, cur);
						break;
					}
					else {
						cur = findParent(p.first);
						p.second.push_back({ a,b });
						break;
					}
				}
			}
		}
		if (cur == -1) {
			v[++group].push_back({ a,b });
			parent.push_back(group);
		}
	}
	int ans = 0;
	vector<int> cnt(v.size());
	for (int i = 0; i < parent.size(); i++) parent[i] = findParent(parent[i]);
	for (int i = 0; i < parent.size(); i++) {
		if (i == parent[i])	ans++;
		cnt[parent[i]] += v[i].size();
	}
	cout << ans << '\n' << *max_element(cnt.begin(), cnt.end());
}