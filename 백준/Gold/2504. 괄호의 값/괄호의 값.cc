#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
string s;
pair<int,int> check(int idx) {
	int ret = 0;
	pair<int, int> p;
	if (s[idx] == '(' && s[idx + 1] == ')') return { 2,idx + 1 };
	if (s[idx] == '[' && s[idx + 1] == ']') return { 3,idx + 1 };
	do {
		p = check(idx + 1);
		ret += p.first;
		idx = p.second;
	} while (idx < s.size() && s[idx + 1] != ')' && s[idx + 1] != ']');
	if (s[idx + 1] == ')') ret *= 2;
	if (s[idx + 1] == ']') ret *= 3;
	return { ret,idx + 1 };
}
bool isValid() {
	stack<char> st;
	st.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		switch (s[i]) {
		case '(':
			st.push(s[i]);
			break;
		case ')':
			if (st.empty()) return false;
			if (st.top() == '(') st.pop();
			else return false;
			break;
		case '[':
			st.push(s[i]);
			break;
		case ']':
			if (st.empty()) return false;
			if (st.top() == '[') st.pop();
			else return false;
			break;
		}
	}
	return st.empty();
}
int main() {
	FAST_IO;
	cin >> s;
	if (!isValid()) {
		cout << 0;
		return 0;
	}
	pair<int, int> p;
	int idx = -1;
	int ans = 0;
	while (idx != s.size() - 1) {
		p = check(idx + 1);
		ans += p.first;
		idx = p.second;
	}
	cout << ans;
}