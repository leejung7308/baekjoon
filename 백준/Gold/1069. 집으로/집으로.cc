#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
double distance(double x, double y) {
	return sqrt(x * x + y * y);
}
int main() {
	FAST_IO;
	cout << fixed << setprecision(13);
	double x, y, d, t;
	cin >> x >> y >> d >> t;
	double dist = distance(x, y);
	if (d < t) {
		cout << dist;
		return 0;
	}
	int q = dist / d;
	double r = dist - d * q;
	double a = t * q + r, b = q != 0 ? t * (q + 1) : t * 2, c = t * (q + 1) + (d - r);
	cout << min({a,b,c});
}