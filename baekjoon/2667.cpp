//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> v;
//vector<vector<int>> vst;
//queue<pair<int, int>> q;
//multiset<int> ans;
//int cnt = 0, n;
//void travel(int x, int y) {
//	if (x < 0 || y < 0 || x > n - 1 || y > n - 1) return;
//	if (vst[x][y] == 1) return;
//	if (v[x][y] == 1) {
//		vst[x][y] = 1;
//		cnt++;
//		q.push(make_pair(x + 1, y));
//		q.push(make_pair(x - 1, y));
//		q.push(make_pair(x, y + 1));
//		q.push(make_pair(x, y - 1));
//	}
//	return;
//}
//int main() {
//	cin >> n;
//	vector<vector<int>> tmp(n, vector<int>(n));
//	vst = v = tmp;
//	for (int i = 0; i < n; i++) {
//		string str;
//		cin >> str;
//		for (int j = 0; j < str.length(); j++) {
//			v[i][j] = str[j] - '0';
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (v[i][j] == 1 && vst[i][j] != 1) {
//				cnt = 0;
//				q.push(make_pair(i, j));
//				while (!q.empty()) {
//					pair<int, int> temp = q.front();
//					q.pop();
//					travel(temp.first, temp.second);
//				}
//				ans.insert(cnt);
//			}
//		}
//	}
//	cout << (int)ans.size() << endl;
//	for (auto i = ans.begin(); i != ans.end(); i++) {
//		cout << *i << endl;
//	}
//}