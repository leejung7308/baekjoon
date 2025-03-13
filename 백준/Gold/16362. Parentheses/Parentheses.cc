#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
string s;
bool isproper = true;
bool isoperator(const char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}
int checkformula(int idx) {
	if (isoperator(s[idx])) return -1;
	bool isPrevAlpha = false;
	int alpha = 0, op = 0;
	while (idx < s.size()) {
		const char c = s[idx++];
		if (c == ' ') continue;
		if (c == '(') {
			if (isPrevAlpha) return -1;
			int next = checkformula(idx);
			if (next != -1) {
				isPrevAlpha = true;
				alpha++;
				idx = next;
			}
			else return -1;
		}
		else if (isalpha(c)) {
			if (isPrevAlpha) return -1;
			isPrevAlpha = true;
			alpha++;
		}
		else if (isoperator(c)) {
			if (!isPrevAlpha) return -1;
			isPrevAlpha = false;
			op++;
		}
		else if (c == ')') {
			if (!isPrevAlpha) return -1; 
			if (op > 1 || alpha == 1) {
				isproper = false;
			}
			break;
		}
	}
	return idx;
}
int main() {
	FAST_IO;
	getline(cin, s);
	s = '(' + s + ')';
	stack<char> st;
	for (const char& c : s) {
		if (c == '(') st.push(c);
		else if (c == ')') {
			if (st.empty()) {
				cout << "error";
				return 0;
			}
			else st.pop();
		}
	}
	if (!st.empty()) {
		cout << "error";
		return 0;
	}
	if (checkformula(0) == -1) cout << "error";
	else {
		string ans = isproper ? "proper" : "improper";
		cout << ans;
	}
}