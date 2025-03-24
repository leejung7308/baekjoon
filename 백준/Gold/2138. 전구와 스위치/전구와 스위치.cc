#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
void turn(string& v, int idx) {
	v[idx - 1] = v[idx - 1] == '1' ? '0' : '1';
	v[idx] = v[idx] == '1' ? '0' : '1';
	v[idx + 1] = v[idx + 1] == '1' ? '0' : '1';
}
int main() {
	FAST_IO;
	int n, cnt = 0, ans=INF;
	string cur,target;
	cin >> n;
	cin >> cur >> target;
	cur = ' ' + cur + ' ';
	target = ' ' + target + ' ';
	string tmp = cur;
	turn(tmp, 1);
	cnt++;
	for (int i = 2; i < tmp.size() - 1; i++) {
		if (tmp[i - 1] != target[i - 1]) turn(tmp, i), cnt++;
	}
	if (tmp[tmp.size() - 2] == target[target.size() - 2]) ans = min(ans, cnt);
	tmp = cur;
	cnt = 0;
	for (int i = 2; i < tmp.size() - 1; i++) {
		if (tmp[i - 1] != target[i - 1]) turn(tmp, i), cnt++;
	}
	if (tmp[tmp.size() - 2] == target[target.size() - 2]) ans = min(ans, cnt);
	if (ans == INF) cout << -1;
	else cout << ans;
}