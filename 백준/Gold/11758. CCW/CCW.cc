#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	pair<int, int> a = { p2.first - p1.first, p2.second - p1.second };
	pair<int, int> b = { p3.first - p1.first, p3.second - p1.second };
	long long c = a.first * b.second - a.second * b.first;
	if (c > 0) return 1;
	if (c == 0) return 0;
	if (c < 0) return -1;
}
int main() {
	FAST_IO;
	pair<int, int> p1, p2, p3;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;
	cout << ccw(p1, p2, p3);
}