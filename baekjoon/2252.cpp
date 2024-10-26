//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	vector<int> student(n);
//	vector<vector<int>> graph(n);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		cin >> a >> b;
//		graph[a - 1].push_back(b - 1);
//		student[b - 1]++;
//	}
//	queue<int> q;
//	for (int i = 0; i < n; i++) {
//		if (student[i] == 0) q.push(i);
//	}
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		cout << cur + 1 << ' ';
//
//		for (int i = 0; i < graph[cur].size(); i++) {
//			if (--student[graph[cur][i]] == 0) q.push(graph[cur][i]);
//		}
//	}
//}