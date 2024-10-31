//#include<bits/stdc++.h>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	priority_queue<int, vector<int>, greater<int>> pq;
//	priority_queue<int> nq;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		if (tmp == 0) {
//			if (nq.empty() && pq.empty()) {
//				cout << "0\n";
//				continue;
//			}
//			if (nq.empty() && !pq.empty()) {
//				cout << pq.top() << '\n';
//				pq.pop();
//				continue;
//			}
//			if (!nq.empty() && pq.empty()) {
//				cout << nq.top() << '\n';
//				nq.pop();
//				continue;
//			}
//			if (abs(nq.top()) <= pq.top()) {
//				cout << nq.top() << '\n';
//				nq.pop();
//			}
//			else {
//				cout << pq.top() << '\n';
//				pq.pop();
//			}
//		}
//		else if (tmp < 0) {
//			nq.push(tmp);
//		}
//		else {
//			pq.push(tmp);
//		}
//	}
//}