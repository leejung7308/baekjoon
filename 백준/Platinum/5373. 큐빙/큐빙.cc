#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<vector<char>> r(3, vector<char>(3, 'b')), l(3, vector<char>(3, 'g')), f(3, vector<char>(3, 'r')), b(3, vector<char>(3, 'o')), u(3, vector<char>(3, 'w')), d(3, vector<char>(3,'y'));
void rotate(vector<vector<char>>& v, int d) {
	vector<vector<char>> t(3, vector<char>(3));
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		if (d == 1) t[i][j] = v[2 - j][i];
		else t[i][j] = v[j][2 - i];
	}
	v = t;
}
void rp() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(f[i][2]);
	for (int i = 0; i < 3; i++) f[i][2] = d[i][2];
	for (int i = 0; i < 3; i++) d[i][2] = b[2 - i][0];
	for (int i = 0; i < 3; i++) b[i][0] = u[2 - i][2];
	for (int i = 0; i < 3; i++) u[i][2] = tmp[i];
	rotate(r, 1);
}
void rm() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(u[i][2]);
	for (int i = 0; i < 3; i++) u[i][2] = b[2 - i][0];
	for (int i = 0; i < 3; i++) b[i][0] = d[2 - i][2];
	for (int i = 0; i < 3; i++) d[i][2] = f[i][2];
	for (int i = 0; i < 3; i++) f[i][2] = tmp[i];
	rotate(r, -1);
}
void lp() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(u[i][0]);
	for (int i = 0; i < 3; i++) u[i][0] = b[2 - i][2];
	for (int i = 0; i < 3; i++) b[i][2] = d[2 - i][0];
	for (int i = 0; i < 3; i++) d[i][0] = f[i][0];
	for (int i = 0; i < 3; i++) f[i][0] = tmp[i];
	rotate(l, 1);
}
void lm() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(f[i][0]);
	for (int i = 0; i < 3; i++) f[i][0] = d[i][0];
	for (int i = 0; i < 3; i++) d[i][0] = b[2 - i][2];
	for (int i = 0; i < 3; i++) b[i][2] = u[2 - i][0];
	for (int i = 0; i < 3; i++) u[i][0] = tmp[i];
	rotate(l, -1);
}
void fp() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(l[i][2]);
	for (int i = 0; i < 3; i++) l[i][2] = d[0][i];
	for (int i = 0; i < 3; i++) d[0][i] = r[2 - i][0];
	for (int i = 0; i < 3; i++) r[i][0] = u[2][i];
	for (int i = 0; i < 3; i++) u[2][i] = tmp[2 - i];
	rotate(f, 1);
}
void fm() {
	vector<char> tmp = u[2];
	for (int i = 0; i < 3; i++) u[2][i] = r[i][0];
	for (int i = 0; i < 3; i++) r[i][0] = d[0][2 - i];
	for (int i = 0; i < 3; i++) d[0][i] = l[i][2];
	for (int i = 0; i < 3; i++) l[i][2] = tmp[2 - i];
	rotate(f, -1);
}
void bp() {
	vector<char> tmp = u[0];
	for (int i = 0; i < 3; i++) u[0][i] = r[i][2];
	for (int i = 0; i < 3; i++) r[i][2] = d[2][2 - i];
	for (int i = 0; i < 3; i++) d[2][i] = l[i][0];
	for (int i = 0; i < 3; i++) l[i][0] = tmp[2 - i];
	rotate(b, 1);
}
void bm() {
	vector<char> tmp;
	for (int i = 0; i < 3; i++) tmp.push_back(l[i][0]);
	for (int i = 0; i < 3; i++) l[i][0] = d[2][i];
	for (int i = 0; i < 3; i++) d[2][i] = r[2 - i][2];
	for (int i = 0; i < 3; i++) r[i][2] = u[0][i];
	for (int i = 0; i < 3; i++) u[0][i] = tmp[2 - i];
	rotate(b, -1);
}
void up() {
	vector<char> tmp;
	tmp = r[0];
	r[0] = b[0];
	b[0] = l[0];
	l[0] = f[0];
	f[0] = tmp;
	rotate(u, 1);
}
void um() {
	vector<char> tmp;
	tmp = f[0];
	f[0] = l[0];
	l[0] = b[0];
	b[0] = r[0];
	r[0] = tmp;
	rotate(u, -1);
}
void dp() {
	vector<char> tmp;
	tmp = f[2];
	f[2] = l[2];
	l[2] = b[2];
	b[2] = r[2];
	r[2] = tmp;
	rotate(d, 1);
}
void dm() {
	vector<char> tmp;
	tmp = r[2];
	r[2] = b[2];
	b[2] = l[2];
	l[2] = f[2];
	f[2] = tmp;
	rotate(d, -1);
}
void printv(const vector<vector<char>>& v) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) cout << v[i][j];
		cout << '\n';
	}
}
int main() {
	FAST_IO;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		r = vector<vector<char>>(3, vector<char>(3, 'b'));
		l = vector<vector<char>>(3, vector<char>(3, 'g'));
		f = vector<vector<char>>(3, vector<char>(3, 'r'));
		b = vector<vector<char>>(3, vector<char>(3, 'o'));
		u = vector<vector<char>>(3, vector<char>(3, 'w'));
		d = vector<vector<char>>(3, vector<char>(3, 'y'));
		while (n--) {
			string s;
			cin >> s;
			switch (s[0]) {
			case 'R':
				if (s[1] == '+') rp();
				else rm();
				break;
			case 'L':
				if (s[1] == '+') lp();
				else lm();
				break;
			case 'F':
				if (s[1] == '+') fp();
				else fm();
				break;
			case 'B':
				if (s[1] == '+') bp();
				else bm();
				break;
			case 'U':
				if (s[1] == '+') up();
				else um();
				break;
			case 'D':
				if (s[1] == '+') dp();
				else dm();
				break;
			}
		}
		printv(u);
	}
}