#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
DIR;
int n, m;
vector<string> v(50);
bool visited[50][50][64];
int ans = INF;
void print(const vector<string>& v) {
	cout << "=======\n";
	for (const string& s : v) cout << s << '\n';
	cout << "=======\n";
}
int isValid(int bit, int idx) { return bit & (1 << idx); }
int bfs(pii start) {
	queue<pair<pii, pii>> q;
	q.push({ start,{0,0} });
	visited[start.first][start.second][0] = true;
	while (!q.empty()) {
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cost = q.front().second.first;
		int bit = q.front().second.second;
		q.pop();
		if (v[cy][cx] == '1') return cost;
		if (v[cy][cx] >= 'a' && v[cy][cx] <= 'f') {
			int idx = v[cy][cx] - 'a';
			int nbit = 1 << idx;
			bit |= nbit;
		}
		for (const pii& d : dir) {
			int ny = cy + d.first;
			int nx = cx + d.second;
			int ncost = cost + 1;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx][bit]) continue;
			if (v[ny][nx] == '#') continue;
			if (v[ny][nx] >= 'A' && v[ny][nx] <= 'F' && !isValid(bit, v[ny][nx] - 'A')) continue;
			q.push({ {ny,nx},{ncost,bit} });
			visited[ny][nx][bit] = true;
		}
	}
	return -1;
}
int main() {
	FAST_IO;
	cin >> n >> m;
	pii start;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '0') {
				start = { i,j };
				v[i][j] = '.';
			}
		}
	}
	cout << bfs(start);
}