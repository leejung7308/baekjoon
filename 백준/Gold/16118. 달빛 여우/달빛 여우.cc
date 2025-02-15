#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int n, m;
vector<vector<pair<int, int>>> edges(4001);
vector<int> F(4001, INF);
vector<vector<int>> W(2, vector<int>(4001, INF));
void dijkstra_F() {
	F[1] = 0;
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (F[cur] < cost) continue;
		for (int i = 0; i < edges[cur].size();i++) {
			pair<int, int> p = edges[cur][i];
			int ncost = cost + p.first * 2;
			int next = p.second;
			if (F[next] > ncost) {
				F[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
}
void dijkstra_W() {
	priority_queue<pair<int, pair<int,bool>>> pq;
	pq.push({ 0,{1,true} });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second.first;
		bool flag = pq.top().second.second;
		pq.pop();
		if (W[!flag][cur] < cost) continue;
		for (int i = 0; i < edges[cur].size();i++) {
			pair<int, int> p = edges[cur][i];
			int ncost = cost + p.first * (flag ? 1 : 4);
			int next = p.second;
			if (W[flag][next] > ncost) {
				W[flag][next] = ncost;
				pq.push({ -ncost,{next,!flag} });
			}
		}
	}
}
int main() {
	FAST_IO;
	cin >> n >> m;
	while (m--) {
		int a, b, d;
		cin >> a >> b >> d;
		edges[a].push_back({ d,b });
		edges[b].push_back({ d,a });
	}
	dijkstra_F();
	dijkstra_W();
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (F[i] < min(W[0][i], W[1][i])) ans++;
	}
	cout << ans;
}