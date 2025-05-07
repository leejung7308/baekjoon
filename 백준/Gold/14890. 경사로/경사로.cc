#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n, l;
	cin >> n >> l;
	vector<vector<int>> v(2 * n, vector<int>(n));
	vector<vector<bool>> used(2 * n, vector<bool>(n));
	int tmp, ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			v[j][i] = tmp;
			v[i + n][j] = tmp;
		}
	}
	for (int j = 0; j < 2 * n; j++){
		vector<int> road = v[j];
		int prev = road[0];
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (abs(prev - road[i]) > 1) {
				flag = false;
				break;
			}
			if (prev == road[i]) continue;
			int d, cur, num, len = 0;
			if (prev < road[i]) d = -1, num = prev, cur = i - 1;
			else d = 1, num = road[i], cur = i;
			while (cur < n && cur >= 0 && road[cur] == num && len < l && !used[j][cur]) {
				len++;
				used[j][cur] = true;
				cur += d;
			}
			if (len < l) {
				flag = false;
				break;
			}
			prev = road[i];
		}
		if (flag) ans++;
	}
	cout << ans;
}