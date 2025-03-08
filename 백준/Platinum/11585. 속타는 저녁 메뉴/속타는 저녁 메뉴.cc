#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
vector<int> table;
string a, b;
int cnt = 0;
void getTable() {
	int j = 1, i = 2;
	table[0] = -1;
	while (i < a.size()) {
		if (a[i] == a[j]) {
			table[i] = j;
			i++;
			j++;
		}
		else if (j > 1) {
			j = table[j - 1] + 1;
		}
		else i++;
	}
}
void kmp() {
	int i = 1, j = 1;
	while (i < b.size()) {
		if (a[j] == b[i]) {
			i++;
			j++;
			if (j == a.size()) {
				cnt++;
				j = table[j - 1] + 1;
			}
		}
		else if (j > 1) {
			j = table[j - 1] + 1;
		}
		else i++;
	}
}
int gcd(int a, int b) {
	while (b != 0) {
		const int n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	a = " " + a;
	b += b;
	b = " " + b;
	b.pop_back();
	table = vector<int>(a.size());
	getTable();
	kmp();
	const int t = gcd(n, cnt);
	cout << cnt / t << '/' << n / t;
}