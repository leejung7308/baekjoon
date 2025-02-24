#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
priority_queue<string, vector<string>, greater<string>> pq;
vector<char> op = { '+','-',' ' };
string f;
void bruteforce(int n, int cur) {
	f += cur+'0';
	if (cur == n) {
		pq.push(f);
		return;
	}
	for (auto& c : op) {
		f += c;
		bruteforce(n, cur + 1);
		f.pop_back();
		f.pop_back();
	}
}
void cal(int* sum, char op, int n){
	switch (op) {
	case '+':
		*sum += n;
		break;
	case '-':
		*sum -= n;
	}
}
void checkzero(string s) {
	int sum = 0;
	char op = '+';
	int i = 0;
	while (i < s.size()) {
		if (s[i] >= 48 && s[i] <= 57) {
			if (i == s.size() - 1) cal(&sum, op, s[i] - '0');
			else {
				int tmp = s[i] - '0';
				for (int j = i + 1; j < s.size(); j += 2) {
					if (s[j] != ' ') break;
					tmp *= 10;
					tmp += s[j + 1] - '0';
					i = j + 1;
				}
				cal(&sum, op, tmp);
			}
		}
		else {
			op = s[i];
		}
		i++;
	}
	if (sum == 0) cout << s << '\n';
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		f = "";
		bruteforce(n,1);
		while (!pq.empty()) {
			checkzero(pq.top());
			pq.pop();
		}
		cout << '\n';
	}
}