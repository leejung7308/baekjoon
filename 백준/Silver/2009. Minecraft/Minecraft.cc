#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<string> h, r, c;
	vector<vector<vector<int>>> m(n, vector<vector<int>>(n, vector<int>(n)));
	bool flag = false;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		r.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		c.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (h[j][k] == '1' && r[i][k] == '1' && c[i][j] == '1') m[i][j][k] = 1;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (h[j][k] == '1') {
				bool check = false;
				for (int i = 0; i < n; i++) {
					if (m[i][j][k]) {
						check = true;
						break;
					}
				}
				if (!check) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (r[i][k] == '1') {
				bool check = false;
				for (int j = 0; j < n; j++) {
					if (m[i][j][k]) {
						check = true;
						break;
					}
				}
				if (!check) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == '1') {
				bool check = false;
				for (int k = 0; k < n; k++) {
					if (m[i][j][k]) {
						check = true;
						break;
					}
				}
				if (!check) {
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << m[i][j][k];
			}
			cout << '\n';
		}
	}
}