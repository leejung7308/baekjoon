//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, m;
//	cin >> n >> m;
//	map<string, int> idx;
//	map<int, string> pokemon;
//	for (int i = 0; i < n; i++) {
//		string in;
//		cin >> in;
//		idx[in] = i + 1;
//		pokemon[i + 1] = in;
//	}
//	for (int i = 0; i < m; i++) {
//		string in;
//		cin >> in;
//		if (isdigit(in[0])) {
//			cout << pokemon[stoi(in)] << '\n';
//		}
//		else {
//			cout << idx[in] << '\n';
//		}
//	}
//}