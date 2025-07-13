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
vector<int> parent;
struct node {
	int a, b;
	double dist;
};
struct cmp {
	bool operator()(const node& a, const node& b) {
		return a.dist > b.dist;
	}
};
double dist(const pair<double, double>& a, const pair<double, double>& b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
int findp(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findp(parent[x]);
}
void uni(int a, int b) {
	if (a > b) swap(a, b);
	parent[b] = a;
}
int main() {
	FAST_IO;
	cout.precision(3);
	int n;
	double ans = 0;
	cin >> n;
	parent.resize(n);
	vector<pair<double, double>> v;
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		pair<double, double> tmp;
		cin >> tmp.first >> tmp.second;
		for (int j = 0; j < v.size(); j++) pq.push({ i,j,dist(tmp,v[j]) });
		v.push_back(tmp);
	}
	while (!pq.empty()) {
		node cur = pq.top();
		pq.pop();
		int pa = findp(cur.a), pb = findp(cur.b);
		if (pa == pb) continue;
		if (pa > pb) swap(pa, pb);
		parent[pb] = pa;
		ans += cur.dist;
	}
	cout << ans;
}