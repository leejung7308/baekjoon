//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, s;
//	cin >> n >> s;
//	vector<int> arr(n+1,0);
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	int f=0, b=1, ans=987654321;
//	int sum = arr[f];
//	if (sum >= s) {
//		cout << 1;
//		return 0;
//	}
//	while (f != b) {
//		if (b == n) {
//			if (sum == s) {
//				ans = min(ans, b - f);
//				break;
//			}
//			else if (sum < s) break;
//		}
//		if (sum < s) {
//			sum += arr[b++];
//		}
//		else if (sum == s) {
//			ans = min(ans, b - f);
//			sum += arr[b++];
//		}
//		else {
//			ans = min(ans, b - f);
//			sum -= arr[f++];
//		}
//	}
//	if (ans == 987654321) cout << 0;
//	else cout << ans;
//}