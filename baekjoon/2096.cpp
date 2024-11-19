//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	vector<int> mindp(3), maxdp(3), v(3);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int a, b, c;
//		cin >> a >> b >> c;
//		v[0] = a + min(mindp[0], mindp[1]);
//		v[1] = b + min({ mindp[0],mindp[1],mindp[2] });
//		v[2] = c + min(mindp[1], mindp[2]);
//		mindp = v;
//		v[0] = a + max(maxdp[0], maxdp[1]);
//		v[1] = b + max({ maxdp[0],maxdp[1],maxdp[2]});
//		v[2] = c + max(maxdp[1], maxdp[2]);
//		maxdp = v;
//	}
//	cout << max({ maxdp[0],maxdp[1],maxdp[2] }) << ' ' << min({ mindp[0],mindp[1],mindp[2] });
//}