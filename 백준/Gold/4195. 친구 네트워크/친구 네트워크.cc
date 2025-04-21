#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
string findp(unordered_map<string, pair<string, int>>& network, const string& x) {
	if (network[x].first == x) return x;
	return network[x].first = findp(network, network[x].first);
}
void uni(unordered_map<string, pair<string, int>>& network, string a, string b) {
	if (a > b) swap(a, b);
	a = findp(network, a);
	b = findp(network, b);
	if (a == b) return;
	network[b].first = a;
	network[a].second += network[b].second;
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		unordered_map<string, pair<string,int>> network;
		while (n--) {
			cin >> a >> b;
			if (network.find(a) == network.end()) network[a] = { a,1 };
			if (network.find(b) == network.end()) network[b] = { b,1 };
			uni(network, a, b);
			cout << network[findp(network, a)].second << '\n';
		}
	}
}