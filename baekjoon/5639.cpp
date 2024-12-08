//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//map<int, pair<int, int>> tree;
//void post(int x) {
//	if (x == 0) return;
//	post(tree[x].first);
//	post(tree[x].second);
//	cout << x << '\n';
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	stack<int> st;
//	int tmp, root;
//	cin >> tmp;
//	root = tmp;
//	tree[tmp] = { 0,0 };
//	st.push(tmp);
//	while (cin >> tmp) {
//		int prev;
//		tree[tmp] = { 0,0 };
//		if (st.top() > tmp) {
//			tree[st.top()].first = tmp;
//			st.push(tmp);
//		}
//		else {
//			while (!st.empty() && st.top() < tmp) {
//				prev = st.top();
//				st.pop();
//			}
//			tree[prev].second = tmp;
//			st.push(tmp);
//		}
//	}
//	post(root);
//}