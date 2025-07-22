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
const vector<pair<int, int>> dir = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
struct node { int y, x, d; };
int n, k, t = 0;
vector<vector<int>> v;
vector<vector<stack<int>>> st;
vector<node> pos;
int main() {
	FAST_IO;
	cin >> n >> k;
	v.resize(n + 1, vector<int>(n + 1));
	st.resize(n + 1, vector<stack<int>>(n + 1));
	pos.resize(k + 1);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> v[i][j];
	for (int i = 1; i <= k; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		pos[i] = { y,x,d };
		st[y][x].push(i);
	}
	while (t++ < 1000) {
		bool flag = false;
		for (int i = 1; i <= k; i++) {
			deque<int> dq;
			int cy = pos[i].y, cx = pos[i].x, cd = pos[i].d;
			int ny = cy + dir[cd].first, nx = cx + dir[cd].second;
			while (true) {
				int cur = st[cy][cx].top();
				st[cy][cx].pop();
				dq.push_front(cur);
				if (cur == i) break;
			}
			if (ny <= 0 || ny > n || nx <= 0 || nx > n || v[ny][nx] == 2) {
				if (cd % 2 == 0) {
					pos[i].d--;
					cd--;
				}
				else {
					pos[i].d++;
					cd++;
				}
				ny = cy + dir[cd].first;
				nx = cx + dir[cd].second;
				if (ny <= 0 || ny > n || nx <= 0 || nx > n || v[ny][nx] == 2) {
					while (!dq.empty()) {
						st[cy][cx].push(dq.front());
						dq.pop_front();
					}
					continue;
				}
			}
			if (v[ny][nx] == 1) {
				while (!dq.empty()) {
					int cur = dq.back();
					pos[cur].y = ny;
					pos[cur].x = nx;
 					dq.pop_back();
					st[ny][nx].push(cur);
				}
			}
			else {
				while (!dq.empty()) {
					int cur = dq.front();
					pos[cur].y = ny;
					pos[cur].x = nx;
					dq.pop_front();
					st[ny][nx].push(cur);
				}
			}
			if (st[ny][nx].size() >= 4) flag = true;
		}
		if (flag) break;
	}
	if (t > 1000) cout << -1;
	else cout << t;
}