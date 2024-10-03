//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long n, ans = 0, sum = 0, min;
//	cin >> n;
//	vector<long long> price(n);
//	vector<long long> dist(n - 1);
//	for (int i = 0; i < n - 1; i++) {
//		cin >> dist[i];
//		sum += dist[i];
//	}
//	min = 10000000000;
//	for (int i = 0; i < n; i++) {
//		cin >> price[i];
//		if (i == n - 1)break;
//		if (i != 0) {
//			if (price[i] < min) {
//				ans -= min * sum;
//				ans += price[i] * sum;
//				min = price[i];
//			}
//		}
//		else {
//			min = price[i];
//			ans += price[i] * sum;
//		}
//		sum -= dist[i];
//	}
//	cout << ans;
//}