#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define DIR8 const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
const vector<pair<int, int>> dir = { {0,0},{ -1,0 },{1,0},{0,-1},{0,1} };
struct node { int s, t, y, x; };
struct shark { int s, d, y, x; };
int n, m, k, cnt = 0;
vector<shark> sd;
vector<bool> live;
vector<vector<pii>> ss;
vector<vector<int>> v;
vector<vector<vector<int>>> pr;
queue<node> q;
queue<shark> sq;
void printv() {
	cout << "===============================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << v[i][j] << ' ';
		cout << "       ";
		for (int j = 0; j < n; j++) cout << '{' << ss[i][j].first << ' ' << ss[i][j].second << '}' << ' ';
		cout << '\n';
	}
	cout << "===============================\n";
}
int main() {
	FAST_IO;
	cin >> n >> m >> k;
	sd.resize(m + 1);
	live.resize(m + 1);
	ss = vector<vector<pii>>(n, vector<pii>(n));
	v = vector<vector<int>>(n, vector<int>(n));
	pr = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(5, vector<int>(4)));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> v[i][j];
		if (v[i][j] == 0) continue;
		cnt++;
		live[v[i][j]] = true;
		ss[i][j] = { v[i][j], 0 };
		q.push({ v[i][j],0,i,j });
		sd[v[i][j]].y = i;
		sd[v[i][j]].x = j;
		sd[v[i][j]].s = v[i][j];
	}
	for (int i = 1; i <= m; i++) cin >> sd[i].d, sq.push(sd[i]);
	for (int i = 1; i <= m; i++) for (int j = 1; j <= 4; j++) for (int k = 0; k < 4; k++) cin >> pr[i][j][k];
	int time;
	for (time = 1; time <= 1000; time++) {
		queue<shark> nq;
		queue<node> ns;
		vector<vector<int>> nv(n, vector<int>(n));
		while (!sq.empty()) {
			shark cs = sq.front();
			sq.pop();
			int s = cs.s, y = cs.y, x = cs.x, d = cs.d;
			int nexty = -1, nextx = -1, nextd = -1;
			for (int i = 0; i < 4; i++) {
				int ny = y + dir[pr[s][d][i]].first, nx = x + dir[pr[s][d][i]].second;
				if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
				if (ss[ny][nx].first == 0) {
					nexty = ny;
					nextx = nx;
					nextd = pr[s][d][i];
					break;
				}
				if (ss[ny][nx].first != s) continue;
				if (nexty == -1 && nextx == -1) nexty = ny, nextx = nx, nextd = pr[s][d][i];
			}
			if (nv[nexty][nextx] != 0) {
				cnt--;
				live[s] = false;
				continue;
			}
			else {
				nv[nexty][nextx] = s;
				nq.push({ s,nextd,nexty,nextx });
				ns.push({ s,time,nexty,nextx });
			}
		}
		sq = nq;
		v = nv;
		while (!ns.empty()) {
			node tmp = ns.front();
			ss[tmp.y][tmp.x] = { tmp.s,tmp.t };
			ns.pop();
			q.push(tmp);
		}
		while (!q.empty() && time - k >= q.front().t) {
			node tmp = q.front();
			q.pop();
			pii cur = ss[tmp.y][tmp.x];
			if (cur.second <= time - k) ss[tmp.y][tmp.x] = { 0,0 };
		}
		//printv();
		if (cnt == 1 && live[1]) break;
	}
	if (cnt > 1 || live[1] == false) cout << -1;
	else cout << time;
}