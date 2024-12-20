//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define endl "\n"
//
//using namespace std;
//
//int main() {
//	int n, m, num;
//	vector<int> a;
//	vector<int> b;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		a.push_back(num);
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++) {
//		cin >> num;
//		b.push_back(num);
//	}
//
//	bool flag = true;
//	vector<int> ans;
//	int max_a, a_idx, max_b, b_idx;
//	while (true) {
//		//각 수열의 최대 공통 값을 찾음
//		while (true) {
//			if (a.size() == 0 || b.size() == 0) {
//				flag = false;
//				break;
//			}
//			max_a = *max_element(a.begin(), a.end());
//			a_idx = max_element(a.begin(), a.end()) - a.begin();
//			max_b = *max_element(b.begin(), b.end());
//			b_idx = max_element(b.begin(), b.end()) - b.begin();
//			if (max_a == max_b) break;
//			else if (max_a > max_b)	a.erase(a.begin() + a_idx);
//			else b.erase(b.begin() + b_idx);
//		}
//		if (!flag) break;
//
//		//최댓값을 ans벡터에 push
//		ans.push_back(max_a);
//
//		//최댓값 보다 작은 인덱스의 값들을 제거
//		int tmp = 0;
//		for (int i = a_idx + 1; i < a.size(); i++) {
//			a[tmp] = a[i];
//			tmp++;
//		}
//		for (int i = 0; i < a_idx + 1; i++) {
//			a.pop_back();
//		}
//		tmp = 0;
//		for (int i = b_idx + 1; i < b.size(); i++) {
//			b[tmp] = b[i];
//			tmp++;
//		}
//		for (int i = 0; i < b_idx + 1; i++) {
//			b.pop_back();
//		}
//	}
//
//	if (!ans.empty()) {
//		cout << ans.size() << endl;
//		for (auto v : ans) cout << v << " ";
//	}
//	else cout << 0;
//
//}