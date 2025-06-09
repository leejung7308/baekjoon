#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
DIR;
struct node {
	pii p;
	int left;
	int cost;
	pii pos() { 
		pii npos = p;
		return npos; 
	}
};
int k, w, h, ans = -1;
int v[200][200];
bool visited[200][200][31];
vector<pair<int, int>> hdir = { {1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1} };
bool notValid(const pii& pos, int left) {
	return pos.first < 0 || pos.first >= h || pos.second < 0 || pos.second >= w || v[pos.first][pos.second] == 1 || visited[pos.first][pos.second][left];
}
void bfs() {
	queue<node> q;
	q.push({ {0,0},k,0 });
	visited[0][0][k];
	while (!q.empty()) {
		pii pos = q.front().pos();
		int left = q.front().left;
		int cost = q.front().cost;
		q.pop();
		if (pos == make_pair(h-1, w-1)) {
			ans = cost;
			break;
		}
		for (const pii& d : dir) {
			pii npos = pos + d;
			if (notValid(npos, left)) continue;
			visited[npos.first][npos.second][left] = true;
			q.push({ npos,left,cost + 1 });
		}
		if (left == 0) continue;
		for (const pii& d : hdir) {
			pii npos = pos + d;
			if (notValid(npos, left - 1)) continue;
			visited[npos.first][npos.second][left-1] = true;
			q.push({ npos,left - 1,cost + 1 });
		}
	}
}
int main() {
	FAST_IO;
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> v[i][j];
	bfs();
	cout << ans;
}