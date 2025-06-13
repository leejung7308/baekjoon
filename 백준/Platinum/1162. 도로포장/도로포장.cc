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
struct node {
	int cur;
	int left;
	LL cost;
};
struct compare {
	bool operator()(const node& a, const node& b) { return a.cost > b.cost; }
};
vector<vector<pair<int, LL>>> v(10001);
vector<vector<LL>> dist(10001, vector<LL>(21, 200000000000));
int n, m, k;
void dijkstra() {
	priority_queue<node, vector<node>, compare> q;
	q.push({ 1,k,0 });
	dist[1][k] = 0;
	while (!q.empty()) {
		int cur = q.top().cur;
		int left = q.top().left;
		LL cost = q.top().cost;
		q.pop();
		if (cost > dist[cur][left]) continue;
		if (cur == n) {
			cout << cost;
			return;
		}
		for (const auto& p : v[cur]) {
			if (dist[p.first][left] > cost + p.second) {
				q.push({ p.first,left,cost + p.second });
				dist[p.first][left] = cost + p.second;
			}
			if (left > 0 && dist[p.first][left - 1] > cost) {
				q.push({ p.first,left - 1,cost });
				dist[p.first][left - 1] = cost;
			}
		}
	}
}
int main() {
	FAST_IO;
	cin >> n >> m >> k;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijkstra();
}