//#include<bits/stdc++.h>
//using namespace std;
//vector<vector<int>> v;
//vector<vector<int>> vst;
//multiset<int> ans;
//int cnt = 0, n;
//void travel(int x, int y) {
//	if (x < 0 || y < 0 || x > n - 1 || y > n - 1) return;
//	if (vst[x][y] == 1) return;
//	if (v[x][y] == 1) {
//		vst[x][y] = 1;
//		cnt++;
//		travel(x + 1, y);
//		travel(x, y + 1);
//		travel(x - 1, y);
//		travel(x, y - 1);
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
//				travel(i, j);
//				ans.insert(cnt);
//			}
//		}
//	}
//	cout << (int)ans.size() << endl;
//	for (auto i = ans.begin(); i != ans.end(); i++) {
//		cout << *i << endl;
//	}
//}