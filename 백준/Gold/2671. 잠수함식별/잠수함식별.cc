#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int main() {
	FAST_IO;
	string s;
	cin >> s;
	bool flag = true;
	int cur = 0;
	if (s[s.size() - 1] == '0') {
		cout << "NOISE";
		return 0;
	}
	while (flag && cur < s.size()) {
		if (s[cur] == '1') { //1
			int zcnt = 0, ocnt = 0;
			cur++;
			while (cur < s.size() && s[cur] == '0') zcnt++, cur++;
			if (zcnt < 2) flag = false;
			else {
				while (cur < s.size() && s[cur] == '1') ocnt++, cur++;
				if (cur + 1 < s.size() && s[cur + 1] == '1') cur += 2;
				else if (cur + 1 < s.size() && s[cur + 1] == '0') {
					if (ocnt == 1) flag = false;
					cur--;
				}
			}
		}
		else {//0
			if (cur + 1 < s.size() && s[cur + 1] == '1') cur += 2;
			else flag = false;
		}
	}
	if (flag) cout << "SUBMARINE";
	else cout << "NOISE";
}