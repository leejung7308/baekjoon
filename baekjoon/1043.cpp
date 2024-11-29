//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	int t;
//	cin >> t;
//	vector<bool> truth(n+1);
//	vector<bool> partyT(m);
//	vector<vector<int>> party(m);
//	vector<vector<int>> included(n + 1);
//	queue<int> q;
//	for (int i = 0; i < t; i++) {
//		int tmp;
//		cin >> tmp;
//		truth[tmp] = true;
//		q.push(tmp);
//	}
//	for (int i = 0; i < m; i++) {
//		int p;
//		cin >> p;
//		for (int j = 0; j < p; j++) {
//			int tmp;
//			cin >> tmp;
//			party[i].push_back(tmp);
//			included[tmp].push_back(i);
//		}
//	}
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		for (int i = 0; i < included[cur].size(); i++) {
//			int curparty = included[cur][i];
//			if (partyT[curparty]) continue;
//			partyT[curparty] = true;
//			for (int j = 0; j < party[curparty].size(); j++) {
//				int curperson = party[curparty][j];
//				if (truth[curperson] == true) continue;
//				truth[curperson] = true;
//				q.push(curperson);
//			}
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < m; i++) {
//		if (!partyT[i]) ans++;
//	}
//	cout << ans;
//}