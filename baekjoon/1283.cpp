//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	int n;
//	vector<char> key;
//	vector<string> v;
//	string input="";
//	cin >> n;
//	cin.ignore();
//	for (int i = 0; i < n; i++) {
//		getline(cin, input);
//		string sub = "";
//		for (int j = 0; j < input.length(); j++) {
//			if (input[j] != ' ') sub.append(1, input[j]);
//			if (input[j] == ' ' || j == input.length() - 1) {
//				v.push_back(sub);
//				sub = "";
//			}
//		}
//		bool end = false;
//		pair<int, int> ans = { -1,-1 };
//		for (int k = 0; k < (int)v.size(); k++) {
//			if (find(key.begin(), key.end(), tolower(v[k][0])) == key.end()) {
//				key.push_back(tolower(v[k][0]));
//				ans = make_pair(k, 0);
//				end = true;
//				break;
//			}
//		}
//		if (end == false) {
//			for (int k = 0; k < (int)v.size(); k++) {
//				for (int h = 0; h < v[k].length(); h++) {
//					if (find(key.begin(), key.end(), tolower(v[k][h])) == key.end()) {
//						key.push_back(tolower(v[k][h]));
//						ans = make_pair(k, h);
//						end = true;
//						break;
//					}
//				}
//				if (end) break;
//			}
//		}
//		for (int j = 0; j < (int)v.size(); j++) {
//			for (int k = 0; k < v[j].length(); k++) {
//				if (ans.first == j && ans.second == k) cout << "[" << v[j][k] << "]";
//				else cout << v[j][k];
//			}
//			cout << " ";
//		}
//		cout << endl;
//		v.clear();
//	}
//}