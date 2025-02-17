#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	string s;
	cin >> s;
	stack<char> st;
	int pcnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') {
			st.push('P');
			pcnt++;
		}
		else if (s[i] == 'A') {
			if (pcnt >= 2 && s[i + 1] == 'P') {
				st.pop();
				pcnt--;
				i++;
			}
			else {
				st.push('A');
			}
		}
	}

	string res = "";
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	if (res == "PPAP" || res == "P") {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}
}