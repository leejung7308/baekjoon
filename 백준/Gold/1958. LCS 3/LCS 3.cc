#include<bits/stdc++.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int res[101][101][101];
void lcs(string a, string b, string c) {
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			for (int k = 1; k < c.size(); k++) {
				if (a[i] == b[j] && b[j] == c[k]) res[i][j][k] = res[i - 1][j - 1][k - 1] + 1;
				else res[i][j][k] = max({ res[i - 1][j][k], res[i][j - 1][k], res[i][j][k - 1] });
			}
		}
	}
}
int main() {
	FAST_IO;
	string a, b, c;
	cin >> a >> b >> c;
	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;
	lcs(a, b, c);
	cout << res[a.size() - 1][b.size() - 1][c.size() - 1];
}