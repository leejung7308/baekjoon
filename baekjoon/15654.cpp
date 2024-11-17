//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<int> ans,v;
//vector<bool> visited;
//void brute(int cnt, int m) {
//	if (cnt == m) {
//		for (int i = 0; i < ans.size(); i++)
//		{
//			cout << ans[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i < v.size(); i++) {
//		if (visited[i]) continue;
//		ans.push_back(v[i]);
//		visited[i] = true;
//		brute(cnt + 1, m);
//		visited[i] = false;
//		ans.pop_back();
//	}
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	v = vector<int>(n);
//	visited = vector<bool>(n);
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	brute(0, m);
//}