//#include<iostream>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int k = 1;
//	unordered_map<int, int> map;
//	while (true) {
//		int a, b;
//		cin >> a >> b;
//		if (a < 0 && b < 0) break;
//		if (a == 0 && b == 0) {
//			int cnt = 0;
//			bool isTree = true;
//			for (auto elem : map) {
//				if (elem.second == 0) cnt++;
//				if (elem.second > 1) {
//					isTree = false;
//				}
//			}
//			if (cnt != 1 && map.size() != 0) {
//				isTree = false;
//			}
//			if (!isTree)
//				cout << "Case " << k << " is not a tree." << endl;
//			else
//				cout << "Case " << k << " is a tree." << endl;
//			k++;
//			map.clear();
//			continue;
//		}
//		if (map.find(a) == map.end()) map[a];
//		map[b]++;
//	}
//}