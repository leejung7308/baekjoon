#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
map<string, bool> has;
void deletestring(string x, int cnt) {
	if (cnt == 0) return;
	vector<pair<int, int>> pos;
	stack<int> st;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '(') st.push(i);
		else if (x[i] == ')') pos.push_back({ st.top(),i }), st.pop();
	}
	for (const pair<int, int>& p : pos) {
		string tmp;
		for (int i = 0; i < x.size(); i++) {
			if (i == p.first || i == p.second) continue;
			tmp.push_back(x[i]);
		}
		if (has[tmp]) continue;
		else {
			has[tmp] = true;
			deletestring(tmp, cnt - 1);
		}
	}
}
int main() {
	FAST_IO;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') cnt++;
	}
	deletestring(s, cnt);
	for (const auto& t : has) cout << t.first << '\n';
}