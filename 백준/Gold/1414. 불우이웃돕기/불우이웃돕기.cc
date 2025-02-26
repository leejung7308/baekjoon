#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
priority_queue<pair<int, pair<int, int>>> pq;
vector<int> parent;
int ans = 0, sum = 0;
int findparent(int i) {
	if (parent[i] == i) return i;
	return parent[i] = findparent(parent[i]);
}
bool checkparent(int a, int b) {
	if (findparent(a) == findparent(b)) return true;
	else return false;
}
void Union(int a, int b) {
	int pa = findparent(a);
	int pb = findparent(b);
	if (pa > pb) parent[pb] = pa;
	else parent[pa] = pb;
}
void kruskal() {
	while (!pq.empty()) {
		int len = -pq.top().first;
		int from = pq.top().second.first;
		int to = pq.top().second.second;
		pq.pop();
		if (!checkparent(from, to)) {
			Union(from, to);
			ans += len;
		}
	}
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	parent = vector<int>(n);
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] >= 'a' && tmp[j] <= 'z') {
				pq.push({ -(tmp[j] - 'a' + 1),{i,j} });
				sum += tmp[j] - 'a' + 1;
			}
			else if (tmp[j] >= 'A' && tmp[j] <= 'Z') {
				pq.push({ -(tmp[j] - 'A' + 27),{i,j} });
				sum += tmp[j] - 'A' + 27;
			}
		}
	}
	kruskal();
	int p = findparent(0);
	for (int i = 1; i < n; i++) {
		if (findparent(i) != p) {
			cout << -1;
			return 0;
		}
	}
	cout << sum - ans;
}