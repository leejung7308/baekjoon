//#include<bits/stdc++.h>
//using namespace std;
//vector<int> v[100];
//int visited[100];
//void dfs(int n) {
//	for (int i = 0; i < (int)v[n].size(); i++) {
//		if (visited[v[n][i]] == 1) {
//			continue;
//		}
//		visited[v[n][i]] = 1;
//		dfs(v[n][i]);
//	}
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int tmp;
//			cin >> tmp;
//			if (tmp == 1) {
//				v[i].push_back(j);
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		memset(visited, 0, sizeof(visited));
//		dfs(i);
//		for (int j = 0; j < n; j++) {
//			cout << visited[j] << " ";
//		}
//		cout << endl;
//	}
//}