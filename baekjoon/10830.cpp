//#include<bits/stdc++.h>
//#include<unordered_map>
//#define INF 987654321
//using namespace std;
//unordered_map<long long, vector<vector<long long>>> memo;
//vector<vector<long long>> multiple(vector<vector<long long>> a, vector<vector<long long>> b) {
//	vector<vector<long long>> ret(a.size(), vector<long long>(a[0].size()));
//	for (int i = 0; i < a.size(); i++) {
//		for (int j = 0; j < a.size(); j++) {
//			for (int k = 0; k < a.size(); k++) {
//				ret[i][j] += a[i][k] * b[k][j];
//				ret[i][j] %= 1000;
//			}
//		}
//	}
//	return ret;
//}
//vector<vector<long long>> power(vector<vector<long long>> origin, long long b) {
//	if (b == 1) return origin;
//	if (b % 2 == 0) {
//		if (memo.find(b) != memo.end()) return memo[b];
//		memo[b] = multiple(power(origin, b / 2), power(origin, b / 2));
//		return memo[b];
//	}
//	else {
//		if (memo.find(b) != memo.end()) return memo[b];
//		memo[b] = multiple(power(origin, b / 2), power(origin, b / 2 + 1));
//		return memo[b];
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	long long n, b;
//	cin >> n >> b;
//	vector<vector<long long>> origin(n,vector<long long>(n));
//	vector<vector<long long>> answer;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> origin[i][j];
//		}
//	}
//	answer = power(origin, b);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << answer[i][j] % 1000 << ' ';
//		}
//		cout << '\n';
//	}
//}