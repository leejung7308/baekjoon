//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	deque<int> arr;
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++) {
//		arr.clear();
//		string func, num;
//		int n;
//		bool isReverse = true;
//		cin >> func;
//		cin >> n;
//		cin >> num;
//		string tmp;
//		for (int j = 0; j < num.size(); j++) {
//			if (isdigit(num[j])) tmp.push_back(num[j]);
//			else if (tmp.size() > 0) {
//				arr.push_back(stoi(tmp));
//				tmp.clear();
//			}
//		}
//		bool isErr = false;
//		for (int j = 0; j < func.size(); j++) {
//			if (func[j] == 'R') isReverse = !isReverse;
//			else if (func[j] == 'D') {
//				if (arr.size() == 0) {
//					cout << "error\n";
//					isErr = true;
//					break;
//				}
//				if (isReverse) arr.pop_front();
//				else arr.pop_back();
//			}
//		}
//		if (isErr) continue;
//		cout << "[";
//		int s = arr.size();
//		for (int j = 0; j < s; j++) {
//			if (isReverse) {
//				cout << arr.front();
//				arr.pop_front();
//			}
//			else {
//				cout << arr.back();
//				arr.pop_back();
//			}
//			if (j != s - 1) cout << ',';
//		}
//		cout << "]\n";
//	}
//}