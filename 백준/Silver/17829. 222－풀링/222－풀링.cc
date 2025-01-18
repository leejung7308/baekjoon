#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int n;
vector<vector<int>> arr;
vector<pair<int, int>> dir = { {0,0}, {0,1},{1,0},{1,1} };
int getsecondnum(int y, int x) {
	vector<int> v;
	for (auto& d : dir) {
		v.push_back(arr[y + d.first][x + d.second]);
	}
	sort(v.begin(), v.end());
	return v[2];
}
void pooling() {
	vector<vector<int>> tmp(arr.size() / 2, vector<int>(arr.size() / 2));
	for (int i = 0; i < arr.size(); i += 2) {
		for (int j = 0; j < arr[i].size(); j += 2) {
			tmp[i / 2][j / 2] = getsecondnum(i, j);
		}
	}
	arr = tmp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	arr = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (arr.size() != 1) {
		pooling();
	}
	cout << arr[0][0];
}