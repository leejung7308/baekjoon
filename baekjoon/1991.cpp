//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//int n;
//map<char, pair<char, char>> tree;
//void pre(char a) {
//	cout << a;
//	if (tree[a].first != '.') pre(tree[a].first);
//	if (tree[a].second != '.') pre(tree[a].second);
//}
//void in(char a) {
//	if (tree[a].first != '.') in(tree[a].first);
//	cout << a;
//	if (tree[a].second != '.') in(tree[a].second);
//}
//void post(char a){
//	if (tree[a].first != '.') post(tree[a].first);
//	if (tree[a].second != '.') post(tree[a].second);
//	cout << a;
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		char root, left, right;
//		cin >> root >> left >> right;
//		tree[root] = { left,right };
//	}
//	pre('A');
//	cout << '\n';
//	in('A');
//	cout << '\n';
//	post('A');
//	cout << '\n';
//}