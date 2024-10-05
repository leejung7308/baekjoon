//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> v;
//vector<int> vst;
//int cnt=0;
//void travel(int idx) {
//	if (vst[idx] == 1) return;
//	vst[idx] = 1;
//	cnt++;
//	for (auto index : v[idx]) {
//		travel(index);
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m, max = -1;
//	cin >> n >> m;
//	vector<int> ans(n+1);
//	vector<vector<int>> tmp(n + 1);
//	vst = ans;
//	v = tmp;
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		v[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++) {
//		vector<int> d(n + 1);
//		vst = d;
//		cnt = 0;
//		travel(i);
//;		if (cnt > max) {
//			max = cnt;
//			ans.clear();
//			ans.push_back(i);
//		}
//		else if (cnt == max) {
//			ans.push_back(i);
//		}
//	}
//	for (int i = 0; i < ans.size(); i++) {
//		cout << ans[i] << " ";
//	}
//}