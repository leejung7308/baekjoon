//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, cnt=0;
//	cin >> n;
//	vector<long long> v;
//	for (int i = 0; i < n + 1; i++) {
//		for (int j = 0; j < n + 1; j++) {
//			for (int k = 0; k < n + 1; k++) {
//				for (int h = 0; h < n + 1; h++) {
//					if (i + j + k + h == n && find(v.begin(), v.end(), i + j * 5 + k * 10 + h * 50) == v.end()) {
//						v.push_back(i + j * 5 + k * 10 + h * 50);
//						cnt++;
//					}
//				}
//			}
//		}
//	}
//	cout << cnt << endl;
//}