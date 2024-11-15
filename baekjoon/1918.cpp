//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int pr = 0;
//	string cal;
//	cin >> cal;
//	stack<char> op;
//	map<char, int> m;
//	m['+'] = m['-'] = 0;
//	m['*'] = m['/'] = 1;
//	m['('] = 2;
//	for (int i = 0; i < cal.size(); i++) {
//		if (isalpha(cal[i])) cout << cal[i];
//		else {
//			if (op.empty()) op.push(cal[i]);
//			else if (cal[i] == ')') {
//				while (op.top() != '(') {
//					cout << op.top();
//					op.pop();
//				}
//				op.pop();
//			}
//			else if (op.top() == '(' || m[op.top()] < m[cal[i]]) op.push(cal[i]);
//			else {
//				while (!op.empty() && op.top() != '(' && m[op.top()] >= m[cal[i]]) {
//					cout << op.top();
//					op.pop();
//				}
//				op.push(cal[i]);
//			}
//		}
//	}
//	while (!op.empty()) {
//		if (op.top() == '(') continue;
//		cout << op.top();
//		op.pop();
//	}
//}