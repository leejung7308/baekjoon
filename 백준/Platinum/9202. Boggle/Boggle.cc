#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int w, t;
vector<string> words;
vector<bool> found;
vector<string> board(4);
vector<vector<bool>> visited;
vector<pair<int, string>> ans;
vector<int> point = { 0,0,0,1,1,2,3,5,11 };
vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
bool dfs(int i, int y, int x, int idx) {
	if (idx == words[i].size()) return true;
	visited[y][x] = true;
	for (auto& d : dir) {
		int ny = y + d.first;
		int nx = x + d.second;
		if (ny >= 4 || ny < 0 || nx >= 4 || nx < 0) continue;
		if (visited[ny][nx]) continue;
		if (board[ny][nx] != words[i][idx]) continue;
		if (dfs(i, ny, nx, idx + 1)) return true;
	}
	visited[y][x] = false;
	return false;
}
int main() {
	FAST_IO;
	cin >> w;
	while (w--) {
		string tmp;
		cin >> tmp;
		words.push_back(tmp);
	}
	cin >> t;
	while (t--) {
		string tmp;
		int p = 0;
		ans.clear();
		found = vector<bool>(words.size(), false);
		for (int i = 0; i < 4; i++) cin >> board[i];
		if(t != 1) getline(cin, tmp);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < words.size(); k++) {
					if (found[k]) continue;
					if (board[i][j] != words[k][0]) continue;
					visited = vector<vector<bool>>(4, vector<bool>(4));
					if (dfs(k, i, j, 1)) {
						ans.push_back({ -words[k].size(),words[k] });
						found[k] = true;
						p += point[words[k].size()];
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << p << ' ' << ans[0].second << ' ' << ans.size() << '\n';
	}
}