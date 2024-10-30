//#include<bits/stdc++.h>
//#define EMP ""
//using namespace std;
//struct N {
//	int cur;
//	int parent;
//	char op;
//};
//vector<pair<int, char>> node(10000);
//vector<bool> visited(10000);
//queue<N> q;
//int a, b;
//int D(int n) {
//	return (n * 2) % 10000;
//}
//int S(int n) {
//	return (n - 1) < 0 ? 9999 : n - 1;
//}
//int L(int n) {
//	int d[4];
//	for (int i = 3; i >= 0; i--) {
//		d[i] = n % 10;
//		n /= 10;
//	}
//	return ((d[1] * 10 + d[2]) * 10 + d[3]) * 10 + d[0];
//}
//int R(int n) {
//	int d[4];
//	for (int i = 3; i >= 0; i--) {
//		d[i] = n % 10;
//		n /= 10;
//	}
//	return ((d[3] * 10 + d[0]) * 10 + d[1]) * 10 + d[2];
//}
//void bfs(int cur, int parent, char op) {
//	if (visited[cur]) return;
//	visited[cur] = true;
//	node[cur] = { parent,op };
//	q.push({ D(cur),cur,'D' });
//	q.push({ S(cur),cur,'S' });
//	q.push({ L(cur),cur,'L' });
//	q.push({ R(cur),cur,'R' });
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	for (int j = 0; j < n; j++) {
//		q = queue<N>();
//		visited = vector<bool>(10000);
//		node = vector<pair<int, char>>(10000);
//		cin >> a >> b;
//		q.push({ a,-1,' ' });
//		stack<char> st;
//		while (!q.empty()) {
//			int cur = q.front().cur;
//			int parent = q.front().parent;
//			char op = q.front().op;
//			q.pop();
//			if (cur == b) {
//				node[cur] = { parent,op };
//				int tmp = cur;
//				while (node[tmp].first != -1) {
//					st.push(node[tmp].second);
//					tmp = node[tmp].first;
//				}
//				break;
//			}
//			bfs(cur, parent, op);
//		}
//		int len = st.size();
//		for (int i = 0; i < len; i++) {
//			cout << st.top();
//			st.pop();
//		}
//		cout << '\n';
//	}
//}