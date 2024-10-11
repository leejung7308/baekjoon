//#include<bits/stdc++.h>
//using namespace std;
//struct Pos {
//	int x, y;
//};
//int n, m, ans=99999999;
//bool selected[13];
//vector<Pos> house, chicken, picked;
//
//int Distance(Pos a, Pos b) {
//	return abs(a.x - b.x) + abs(a.y - b.y);
//}
//
//void FindMinDist() {
//	int result = 0;
//	for (int i = 0; i < house.size(); i++) {
//		int min_d = 999999999;
//		for (int j = 0; j < picked.size(); j++) {
//			min_d = min(min_d, Distance(house[i], picked[j]));
//		}
//		result += min_d;
//	}
//	ans = min(ans, result);
//}
//
//void PickChicken(int idx, int cnt) {
//	if (cnt == m) {
//		FindMinDist();
//		return;
//	}
//	for (int i = idx; i < chicken.size(); i++) {
//		if (selected[i] == true) continue;
//		selected[i] = true;
//		picked.push_back(chicken[i]);
//		PickChicken(i, cnt + 1);
//		selected[i] = false;
//		picked.pop_back();
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int tmp;
//			cin >> tmp;
//			if (tmp == 2) chicken.push_back({ i,j });
//			else if (tmp == 1) house.push_back({ i,j });
//		}
//	}
//	PickChicken(0, 0);
//	cout << ans << endl;
//}