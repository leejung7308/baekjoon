#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
vector<vector<int>> v;
bool isValid(int y, int x) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	if (v[y][x] == 1) return false;
	if (v[y][x] == 2) return false;
	if (v[y][x] == 0) return true;
	return false;
}
bool isNotWall(int y, int x) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	if (v[y][x] == 1) return false;
	if (v[y][x] == 2 || v[y][x] == 0) return true;
	return false;
}
bool valid(int y, int x, int d) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	if (d == 0) {
		if (isValid(y - 1, x)) clean(y - 1, x, 0);
		else if (isValid(y, x - 1)) clean(y, x - 1, 3);
		else if (isValid(y + 1, x)) clean(y + 1, x, 2);
		else if (isValid(y, x + 1)) clean(y, x + 1, 1);
		else return false;
	}
	else if (d == 3) {
		if (isValid(y, x - 1)) clean(y, x - 1, 3);
		else if (isValid(y + 1, x)) clean(y + 1, x, 2);
		else if (isValid(y, x + 1)) clean(y, x + 1, 1);
		else if (isValid(y - 1, x)) clean(y - 1, x, 0);
		else return false;
	}
	else if (d == 2) {
		if (isValid(y + 1, x)) clean(y + 1, x, 2);
		else if (isValid(y, x + 1)) clean(y, x + 1, 1);
		else if (isValid(y - 1, x)) clean(y - 1, x, 0);
		else if (isValid(y, x - 1)) clean(y, x - 1, 3);
		else return false;
	}
	else if (d == 1) {
		if (isValid(y, x + 1)) clean(y, x + 1, 1);
		else if (isValid(y - 1, x)) clean(y - 1, x, 0);
		else if (isValid(y, x - 1)) clean(y, x - 1, 3);
		else if (isValid(y + 1, x)) clean(y + 1, x, 2);
		else return false;
	}
}
void clean(int y, int x, int D) {
	if (v[y][x] == 0) {
		v[y][x] = 2;
		ans++;
	}
	if (valid(y, x, D));
	else {
		switch (D) {
		case 0:
			if (isNotWall(y + 1, x)) clean(y + 1, x, D);
			else return;
			break;
		case 1:
			if (isNotWall(y, x - 1)) clean(y, x - 1, D);
			else return;
			break;
		case 2:
			if (isNotWall(y - 1, x)) clean(y - 1, x, D);
			else return;
			break;
		case 3:
			if (isNotWall(y, x + 1)) clean(y, x + 1, D);
			else return;
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int y, x, d;
	cin >> n >> m;
	cin >> y >> x >> d;
	v = vector<vector<int>>(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	clean(y, x, d);
	cout << ans << endl;
}