//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, k, ans=0;
//	cin >> n >> k;
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	while (k > 0) {
//		for (int i = n - 1; i >= 0; i--) {
//			if (v[i] <= k) {
//				k -= v[i];
//				ans++;
//				break;
//			}
//		}
//	}
//	cout << ans;
//}