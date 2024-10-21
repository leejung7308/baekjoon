//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	double n;
//	cin >> n;
//	if (n == 0) {
//		cout << 0;
//		return 0;
//	}
//	double r = round(n * 15 / 100);
//	vector<int> v(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	double sum = 0;
//	for (int i = r; i < n - r; i++) {
//		sum += v[i];
//	}
//	double avg = round(sum / (n - r * 2));
//	cout << (int)avg;
//}