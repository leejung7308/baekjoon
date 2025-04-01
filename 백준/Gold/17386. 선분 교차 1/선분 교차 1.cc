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
bool iscrossed(pair<int, int> la1, pair<int, int> la2, pair<int, int> lb1, pair<int, int> lb2) {
	int c1 = ccw(la1, la2, lb1) * ccw(la1, la2, lb2);
	int c2 = ccw(lb1, lb2, la1) * ccw(lb1, lb2, la2);
	if (c1 == 0 && c2 == 0) {
		if (max(la1, la2) > max(lb1, lb2) && min(la1, la2) <= max(lb1, lb2)) return true;
		if (max(la1, la2) < max(lb1, lb2) && max(la1, la2) >= min(lb1, lb2)) return true;
		if (max(la1, la2) == max(lb1, lb2) || min(la1, la2) == min(lb1, lb2)) return true;
		return false;
	}
	if (c1 <= 0 && c2 <= 0) return true;
	return false;
}
int main() {
	FAST_IO;
	pair<int, int> a1, a2, b1, b2;
	cin >> a1.first >> a1.second >> a2.first >> a2.second >> b1.first >> b1.second >> b2.first >> b2.second;
	if (iscrossed(a1, a2, b1, b2)) cout << 1;
	else cout << 0;
}