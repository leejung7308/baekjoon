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
bool iscrossed(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return ab <= 0 && cd <= 0;
}
bool isinside(pair<int, int> p, pair<int, int> r1, pair<int, int> r2) {
	int x1 = min(r1.first, r2.first);
	int x2 = max(r1.first, r2.first);
	int y1 = min(r1.second, r2.second);
	int y2 = max(r1.second, r2.second);
	return (x1 <= p.first && p.first <= x2 && y1 <= p.second && p.second <= y2);
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		pair<int, int> a, b;
		pair<int, int> r1, r2;
		cin >> a.first >> a.second >> b.first >> b.second;
		cin >> r1.first >> r1.second >> r2.first >> r2.second;
		pair<int, int> tl = { min(r1.first, r2.first), max(r1.second, r2.second) };
		pair<int, int> tr = { max(r1.first, r2.first), max(r1.second, r2.second) };
		pair<int, int> bl = { min(r1.first, r2.first), min(r1.second, r2.second) };
		pair<int, int> br = { max(r1.first, r2.first), min(r1.second, r2.second) };
		bool crossed = false;

		if (iscrossed(a, b, tl, tr) ||
			iscrossed(a, b, tr, br) ||
			iscrossed(a, b, br, bl) ||
			iscrossed(a, b, bl, tl)) {
			crossed = true;
		}

		if (isinside(a, r1, r2) && isinside(b, r1, r2)) {
			crossed = true;
		}

		cout << (crossed ? "T\n" : "F\n");
	}
}