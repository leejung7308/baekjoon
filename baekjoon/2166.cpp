//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n;
//vector<pair<int, int>> v;
//long double solution(int i, int j) {
//	long double x1 = v[0].first, y1 = v[0].second;
//	long double x2 = v[i].first, y2 = v[i].second;
//	long double x3 = v[j].first, y3 = v[j].second;
//	return (x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3) / 2;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	long double ans = 0;
//	while (n--) {
//		int x, y;
//		cin >> x >> y;
//		v.push_back({ x,y });
//	}
//	for (int i = 0; i < v.size() - 1; i++) {
//		ans += solution(i, i + 1);
//	}
//	cout << fixed;
//	cout.precision(1);
//	cout << abs(ans) << '\n';
//}