//#include<bits/stdc++.h>
//#include<unordered_map>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, t;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		vector<int> v;
//		unordered_map<string, int> clothes;
//		cin >> n;
//		int ans = 1;
//		for (int j = 0; j < n; j++) {
//			string name, category;
//			cin >> name >> category;
//			clothes[category]++;
//		}
//		for (auto it = clothes.begin(); it != clothes.end(); it++) {
//			v.push_back(it->second);
//		}
//		for (int j = 0; j < v.size(); j++) {
//			ans *= v[j] + 1;
//		}
//		cout << ans-1 << '\n';
//	}
//}