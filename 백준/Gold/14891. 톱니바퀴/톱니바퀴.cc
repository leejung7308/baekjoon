#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<string> v(4);
vector<pair<int, int>> vp(4);
void rotateR(int cur, int d) {
	if (cur + 1 >= 4 || v[cur + 1][vp[cur + 1].first % 8] == v[cur][vp[cur].second % 8]) return;
	rotateR(cur + 1, -d);
	vp[cur + 1].first -= d;
	vp[cur + 1].second -= d;
}
void rotateL(int cur, int d) {
	if (cur - 1 < 0 || v[cur - 1][vp[cur - 1].second % 8] == v[cur][vp[cur].first % 8]) return;
	rotateL(cur - 1, -d);
	vp[cur - 1].first -= d;
	vp[cur - 1].second -= d;
}
int main() {
	FAST_IO;
	int zcnt = 0;
	for (int i = 0; i < 4; i++) {
		cin >> v[i];
		for (int j = 0; j < 8; j++) if (v[i][j] == '0') zcnt++;
	}
	if (zcnt == 0) {
		cout << 15;
		return 0;
	}
	if (zcnt == 32) {
		cout << 0;
		return 0;
	}
	vp[0] = { 106,106 };
	vp[1] = vp[2] = { 102,106 };
	vp[3] = { 102,102 };
	int k;
	cin >> k;
	while (k--) {
		int n, d;
		cin >> n >> d;
		n--;
		d *= -1;
		/*cout << "=======\n";
		for (int i = 0; i < 4; i++) {
			cout << v[i] << '\n';
			for (int j = 0; j < 8; j++) {
				if (vp[i].first == vp[i].second && vp[i].first % 8 == j) cout << 'H';
				else if (vp[i].first % 8 == j) cout << 'L';
				else if (vp[i].second % 8 == j) cout << 'R';
				else cout << ' ';
			}
			cout << '\n';
		}*/
		rotateR(n, d);
		rotateL(n, d);
		vp[n].first += d;
		vp[n].second += d;
		/*for (int i = 0; i < 4; i++) {
			cout << v[i] << '\n';
			for (int j = 0; j < 8; j++) {
				if (vp[i].first == vp[i].second && vp[i].first % 8 == j) cout << 'H';
				else if (vp[i].first % 8 == j) cout << 'L';
				else if (vp[i].second % 8 == j) cout << 'R';
				else cout << ' ';
			}
			cout << '\n';
		}
		cout << "=======\n";*/
	}
	vector<int> point = { 1,2,4,8 };
	int ans = 0;
	for (int i = 0; i < 3; i++) if (v[i][(vp[i].second - 2) % 8] == '1') ans += point[i];
	if (v[3][(vp[3].first + 2) % 8] == '1') ans += point[3];
	cout << ans;
}