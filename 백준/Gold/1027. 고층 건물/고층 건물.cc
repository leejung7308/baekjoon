#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	long long c = (long long)(p2.first - p1.first) * (p3.second - p2.second) - (long long)(p2.second - p1.second) * (p3.first - p2.first);
	if (c > 0) return 1;
	if (c == 0) return 0;
	if (c < 0) return -1;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<int> height(n), cnt(n);
	for (int i = 0; i < n; i++) cin >> height[i];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			bool flag = false;
			for (int k = i + 1; k < j && !flag; k++) if (ccw({ i,height[i] }, { j,height[j] }, { k,height[k] }) >= 0) flag = true;
			if (flag) continue;
			cnt[i]++, cnt[j]++;
		}
	}
	cout << *max_element(cnt.begin(), cnt.end());
}