#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
struct manipulate {
	int l, r, c;
};
bool isascending(const string& s) {
	for (int i = 0; i < s.size() - 1; i++) {
		int cur, next;
		if (s[i] == 'A') cur = 10;
		else cur = s[i] - '0';
		if (s[i + 1] == 'A') next = 10;
		else next = s[i + 1] - '0';
		if (cur > next) return false;
 	}
	return true;
}
bool comp(const manipulate& a, const manipulate& b) {
	return a.c < b.c;
}
void printv(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++)cout << v[i] << ' ';
	cout << '\n';
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		if (tmp == "10") s += 'A';
		else s += tmp;
	}
	int m;
	cin >> m;
	vector<manipulate> manipulates(m);
	unordered_map<string, int> memo;
	for (int i = 0; i < m; i++) cin >> manipulates[i].l >> manipulates[i].r >> manipulates[i].c;
	if (isascending(s)) {
		cout << 0;
		return 0;
	}
	priority_queue<pair<int,string>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		string cur = pq.top().second;
		pq.pop();
		if (isascending(cur)) {
			cout << cost;
			return 0;
		}
		if (memo.find(cur) != memo.end()) continue;
		memo[cur] = cost;
		for (int i = 0; i < m; i++) {
			int ncost = cost + manipulates[i].c;
			string next = cur;
			swap(next[manipulates[i].l - 1], next[manipulates[i].r - 1]);
			pq.push({ -ncost,next });
		}
	}
	cout << -1;
}