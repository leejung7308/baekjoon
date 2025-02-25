#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		vector<string> num;
		bool flag = false;
		cin >> n;
		while (n--) {
			string tmp;
			cin >> tmp;
			num.push_back(tmp);
		}
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size() - 1; i++) {
			string cur = num[i];
			string comp = num[i + 1];
			if (cur.size() >= comp.size()) continue;
			if (cur == comp.substr(0, cur.size())) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
}