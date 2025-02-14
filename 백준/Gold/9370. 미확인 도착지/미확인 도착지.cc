#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int T, n, m, t, s, g, h, a, b, d, x;
vector<vector<pair<int,int>>> edges;
vector<int> candidate;
vector<int> S, G, H;
void dijkstra(int start, vector<int>& arr) {
	arr = vector<int>(n + 1, INF);
	arr[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (auto& p : edges[cur]) {
			int next = p.first;
			int ncost = cost + p.second;
			if (arr[next] > ncost) {
				arr[next] = ncost;
				pq.push({ -ncost,next });
			}
		}
	}
}
int main() {
	FAST_IO;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		edges = vector<vector<pair<int,int>>>(n + 1);
		candidate = vector<int>();
		while (m--) {
			cin >> a >> b >> d;
			edges[a].push_back({ b,d });
			edges[b].push_back({ a,d });
		}
		while (t--) {
			cin >> x;
			candidate.push_back(x);
		}
		sort(candidate.begin(), candidate.end());
		dijkstra(s, S);
		dijkstra(g, G);
		dijkstra(h, H);
		for (int& c : candidate) {
			if (S[c] == S[g] + G[h] + H[c] || S[c] == S[h] + H[g] + G[c]) cout << c << ' ';
		}
		cout << '\n';
	}
}