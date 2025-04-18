#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
const pair<int, int> operator+(const pair<int, int>& lhs, const pair<int,int>& rhs) {
	return { lhs.first + rhs.first,lhs.second + rhs.second };
}
const pair<int, int> operator-(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return { lhs.first - rhs.first,lhs.second - rhs.second };
}
bool isvalid(const pair<int, int>& pos, const vector<vector<char>>& v, const vector<vector<bool>>& visited, int h, int w) {
	return pos.first < h + 2 && pos.first >= 0 && pos.second < w + 2 && pos.second >= 0 && v[pos.first][pos.second] != '*' && !visited[pos.first][pos.second];
}
void printv(const vector<vector<char>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) cout << v[i][j];
		cout << '\n';
	}
	cout << "--------------------------\n";
}
int main() {
	FAST_IO;
	DIR;
	int t;
	cin >> t;
	while (t--) {
		int h, w, ans = 0;
		cin >> h >> w;
		vector<vector<char>> v(h + 2, vector<char>(w + 2, '.'));
		vector<vector<bool>> visited(h + 2, vector<bool>(w + 2));
		vector<pair<int, int>> entrance;
		vector<queue<pair<int, int>>> dpos(26);
		string keys;
		vector<bool> key(26);
		for (int i = 1; i <= h; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 1; j <= w; j++) v[i][j] = tmp[j - 1];
		}
		//printv(v);
		cin >> keys;
		for (const char& c : keys) {
			if (c == '0') break;
			key[c - 'a'] = true;
		}
		visited[0][0] = true;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (const auto& d : dir) {
				pair<int, int> next = cur + d;
				if (!isvalid(next, v, visited, h, w)) continue;
				char c = v[next.first][next.second];
				if (c >= 'A' && c <= 'Z' && !key[c - 'A']) {
					dpos[c - 'A'].push(next);
					continue;
				}
				else if (c >= 'a' && c <= 'z' && !key[c - 'a']) {
					key[c - 'a'] = true;
					while (!dpos[c - 'a'].empty()) {
						pair<int, int> d = dpos[c - 'a'].front();
						dpos[c - 'a'].pop();
						visited[d.first][d.second] = true;
						q.push(d);
					}
				}
				else if (c == '$') ans++;
				visited[next.first][next.second] = true;
				q.push(next);
			}
		}
		cout << ans << '\n';
	}
}