#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int k, shortest = INF, longest = -1;
		string w;
		unordered_map<char, vector<int>> idx;
		cin >> w >> k;
		for (int i = 0; i < w.size(); i++) idx[w[i]].push_back(i);
		for (auto& c : idx) {
			if (c.second.size() < k) continue;
			for (int i = 0; i < c.second.size() - k + 1; i++) {
				int tmp = c.second[i + k - 1] - c.second[i] + 1;
				if (shortest > tmp) shortest = tmp;
				if (longest < tmp) longest = tmp;
			}
		}
		if (shortest != INF) cout << shortest << ' ' << longest << '\n';
		else cout << -1 << '\n';
	}
}