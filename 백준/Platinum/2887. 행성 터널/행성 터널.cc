#include<bits/stdc++.h>
#include<unordered_map>
#define INF 2000000001
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> parent;
int findp(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findp(parent[x]);
}
void uni(int a, int b) {
	a = findp(a);
	b = findp(b);
	a < b ? parent[b] = a : parent[a] = b;
}
struct pair_hash {
	std::size_t operator()(const std::pair<int, int>& p) const {
		return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
	}
};
struct pos {
	int x;
	int y;
	int z;
};
bool compx(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.x < b.second.x;
}
bool compy(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.y < b.second.y;
}
bool compz(const pair<int, pos>& a, const pair<int, pos>& b) {
	return a.second.z < b.second.z;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) parent.push_back(i);
	vector<pair<int,pos>> v(n);
	unordered_map<pair<int, int>, int, pair_hash> graph;
	for (int i = 0; i < n; i++) cin >> v[i].second.x >> v[i].second.y >> v[i].second.z, v[i].first = i;
	sort(v.begin(), v.end(), compx);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		if (v[i].first < v[i + 1].first) a = v[i].first, b = v[i + 1].first;
		else a = v[i + 1].first, b = v[i].first;
		if (graph.find(make_pair(a,b)) != graph.end()) graph[{a, b}] = min(graph[{a, b}], abs(v[i].second.x - v[i + 1].second.x));
		else graph[{a, b}] = abs(v[i].second.x - v[i + 1].second.x);
	}
	sort(v.begin(), v.end(), compy);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		if (v[i].first < v[i + 1].first) a = v[i].first, b = v[i + 1].first;
		else a = v[i + 1].first, b = v[i].first;
		if (graph.find(make_pair(a, b)) != graph.end()) graph[{a, b}] = min(graph[{a, b}], abs(v[i].second.y - v[i + 1].second.y));
		else graph[{a, b}] = abs(v[i].second.y - v[i + 1].second.y);
	}
	sort(v.begin(), v.end(), compz);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		if (v[i].first < v[i + 1].first) a = v[i].first, b = v[i + 1].first;
		else a = v[i + 1].first, b = v[i].first;
		if (graph.find(make_pair(a, b)) != graph.end()) graph[{a, b}] = min(graph[{a, b}], abs(v[i].second.z - v[i + 1].second.z));
		else graph[{a, b}] = abs(v[i].second.z - v[i + 1].second.z);
	}
	priority_queue<pair<int, pair<int, int>>>pq;
	for (const auto& p : graph) pq.push({ -p.second,p.first });
	long long ans = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int a = pq.top().second.first, b = pq.top().second.second;
		pq.pop();
		if (findp(a) != findp(b)) ans+=cost, uni(a, b);
	}
	cout << ans;
}