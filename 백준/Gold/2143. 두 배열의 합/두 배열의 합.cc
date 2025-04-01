#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int t;
	long long ans = 0;
	cin >> t;
	int n;
	cin >> n;
	vector<int> ndp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ndp[i];
		ndp[i] += ndp[i - 1];
	}
	int m;
	cin >> m;
	vector<int> mdp(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> mdp[i];
		mdp[i] += mdp[i - 1];
	}
	unordered_map<int, long long> ncnt, mcnt;
	for (int i = 0; i < n; i++) for (int j = i + 1; j <= n; j++) ncnt[ndp[j] - ndp[i]]++;
	for (int i = 0; i < m; i++) for (int j = i + 1; j <= m; j++) mcnt[mdp[j] - mdp[i]]++;
	for (const auto& p : ncnt) ans += p.second * mcnt[t - p.first];
	cout << ans;
}