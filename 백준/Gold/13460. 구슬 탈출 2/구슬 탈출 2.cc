#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct item {
	pair<int, int> r, b;
	int c;
};
string pos(const pair<int, int>& r, const pair<int, int>& b) {
	return to_string(r.first) + to_string(r.second) + to_string(b.first) + to_string(b.second);
}
const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first + b.first,a.second + b.second };
}
const pair<int, int> operator-(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first - b.first,a.second - b.second };
}
void printb(const vector<string>& B, const pair<int, int>& r, const pair<int, int>& b) {
	cout << "--------------------------\n";
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < B[0].size(); j++) {
			if (r == make_pair(i, j)) cout << 'R';
			else if (b == make_pair(i, j)) cout << 'B';
			else cout << B[i][j];
		}
		cout << '\n';
	}
}
int bfs(vector<string>& board, pair<int, int>& r, pair<int, int>& b) {
	DIR;
	unordered_map<string, bool> visited;
	queue<item> q;
	q.push({ r,b,0 });
	visited[pos(r, b)] = true;
	while (!q.empty()) {
		pair<int, int> cr = q.front().r, cb = q.front().b;
		int cc = q.front().c;
		q.pop();
		if (cc >= 10) continue;
		for (const auto& d : dir) {
			pair<int, int> nr = cr, nb = cb;
			int nc = cc + 1;
			bool rf = false, bf = false;
			while (true) {
				bool moved = false;
				if (!rf && board[nr.first][nr.second] != '#') nr = nr + d, moved = true;
				if (!bf && board[nb.first][nb.second] != '#') nb = nb + d;
				if (board[nr.first][nr.second] == 'O') rf = true;
				if (board[nb.first][nb.second] == 'O') bf = true;
				if (bf) break;
				if (rf && board[nb.first][nb.second] == '#') break;
				if (nr == nb) {
					moved ? nr = nr - d : nb = nb - d;
					break;
				}
				if (board[nr.first][nr.second] == '#' && board[nb.first][nb.second] == '#') break;
			}
			if (bf) continue;
			if (rf) return nc;
			nr = nr - d;
			nb = nb - d;
			if (visited[pos(nr, nb)]) continue;
			visited[pos(nr, nb)] = true;
			q.push({ nr,nb,nc });
		}
	}
	return -1;
}
int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	pair<int, int> r, b;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') r = { i,j }, board[i][j] = '.';
			if (board[i][j] == 'B') b = { i,j }, board[i][j] = '.';
		}
	}
	cout << bfs(board, r, b);
}