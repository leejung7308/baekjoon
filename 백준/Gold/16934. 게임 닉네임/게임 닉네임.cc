#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	FAST_IO;
	unordered_map<string, int> dup;
	unordered_map<string, vector<string>> nickname;
	int n;
	cin >> n;
	while (n--) {
		string in;
		cin >> in;
		if (dup[in] != 0) {
			dup[in]++;
			cout << in << dup[in] << '\n';
			continue;
		}
		dup[in] = 1;
		string tmp;
		for (int i = 0; i < in.size(); i++) {
			tmp.push_back(in[i]);
			if (nickname[tmp].size()) {
				for (const string& s : nickname[tmp]) {
					while (i + 1 < s.size() && i + 1 < in.size()) {
						if (s[i + 1] == in[i + 1]) tmp.push_back(in[i++ + 1]);
						else break;
					}
				}
			}
			else {
				nickname[tmp].push_back(in);
				break;
			}
		}
		cout << tmp << '\n';
	}
}