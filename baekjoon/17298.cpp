//#include<bits/stdc++.h>
//using namespace std;
//int n;
//vector<int> v, ans;
//int find(int cur, int idx) {
//	if (idx == -1) return -1;
//	if (v[cur] < v[idx]) return idx;
//	else if (v[cur] == v[idx]) return ans[idx];
//	else return find(cur, ans[idx]);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	v = ans = vector<int>(n+1);
//	v[0] = -1;
//	for (int i = 1; i <= n; i++) {
//		int tmp;
//		cin >> tmp;
//		v[i] = tmp;
//	}
//	ans[n] = -1;
//	for (int i = n - 1; i > 0; i--) {
//		ans[i] = find(i, i + 1);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (ans[i] == -1)cout << "-1 ";
//		else cout << v[ans[i]] << ' ';
//	}
//}