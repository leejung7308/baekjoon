//#include<bits/stdc++.h>
//#include<unordered_map>
//using namespace std;
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, s, m, ans=-1;
//	unordered_map<int, int> bfs;
//	cin >> n >> s >> m;
//	bfs[s]=0;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		unordered_map<int,int> v;
//		for (auto & elem : bfs) {
//			if (elem.first - tmp >= 0) {
//				v[elem.first - tmp] = 0;
//				if (i == n - 1) {
//					ans = max(elem.first - tmp, ans);
//				}
//			}
//			
//			if (elem.first + tmp <= m) {
//				v[elem.first + tmp] = 0;
//				if (i == n - 1) {
//					ans = max(elem.first + tmp, ans);
//				}
//			}
//		}
//		bfs = v;
//	}
//	cout << ans << endl;
//}