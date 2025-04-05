#include<bits/stdc++.h>
#include<unordered_map>
#include<math.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	cout << fixed;
	cout.precision(3);
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double pi = acos(-1);
	if (r1 + r2 <= dist) {
		cout << 0.000;
		return 0;
	}
	if (dist + r1 <= r2) {
		cout << r1 * r1 * pi;
		return 0;
	}
	if (dist + r2 <= r1) {
		cout << r2 * r2 * pi;
		return 0;
	}
	double t1, t2;
	t1 = 2 * acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));
	t2 = 2 * acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist));
	double c1 = 0.5 * r1 * r1 * sin(t1), c2 = 0.5 * r2 * r2 * sin(t2);
	double ans = 0.5 * r1 * r1 * t1 - c1 + 0.5 * r2 * r2 * t2 - c2;
	cout << ans;
}