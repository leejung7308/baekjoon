//#include<bits/stdc++.h>
//using namespace std;
//int n, cnt=0;
//vector<int> col;
//bool check(int level) {
//	for (int i = 0; i < level; i++) {
//		if (col[level] == col[i]) return false;
//		if (abs(col[level] - col[i]) == level - i) return false;
//	}
//	return true;
//}
//void place(int x) {
//	if (x == n) {
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		col[x] = i;
//		if (check(x)) {
//			place(x + 1);
//		}
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	col = vector<int>(n);
//	place(0);
//	cout << cnt << '\n';
//}