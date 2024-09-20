//#include<iostream>
//#include<algorithm>
//using namespace std;
//#pragma warning(disable:6031)
//int main() {
//	int cnt;
//	scanf("%d", &cnt);
//	cnt++;
//	int** dp = new int* [cnt];
//	for (int i = 0; i < cnt; i++) {
//		dp[i] = new int[cnt];
//	}
//	dp[0][0] = 0;
//	for (int i = 1; i < cnt; i++) {
//		int tmp;
//		scanf("%d", &tmp);
//		if (i == 1) {
//			dp[0][i] = tmp;
//			continue;
//		}
//		else if (i == 2) {
//			dp[0][i] = tmp;
//			dp[1][i] = dp[0][1] + tmp;
//		}
//		else if (i == 3) {
//			dp[i - 2][i] = dp[0][i - 2] + tmp;
//			dp[i - 1][i] = dp[0][i - 1] + tmp;
//			continue;
//		}
//		else {
//			dp[i - 2][i] = max(dp[i - 4][i - 2], dp[i - 3][i - 2]) + tmp;
//			dp[i - 1][i] = dp[i - 3][i - 1] + tmp;
//		}
//	}
//	if (cnt == 2) {
//		cout << dp[0][1];
//		return 0;
//	}
//	else if (cnt == 3) {
//		cout << dp[1][2];
//		return 0;
//	}
//
//	cout << max(dp[cnt - 3][cnt - 1], dp[cnt - 2][cnt - 1]);
//	return 0;
//}