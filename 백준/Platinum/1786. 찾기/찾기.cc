#include<bits/stdc++.h>
#define INF 987654321
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
string t = " ", p = " ";
vector<int> table, idx;
void createtable() {
	int i = 2, j = 1;
	table[0] = -1;
	while (i < p.size()) {
		if (p[i] == p[j]) {
			table[i] = j;
			i++;
			j++;
		}
		else if (j > 1) {
			j = table[j - 1] + 1;
		}
		else {
			i++;
		}
	}
}
void kmp() {
	createtable();
	int i, j;
	i = j = 1;
	while (i < t.size()) {
		if (t[i] == p[j]) {
			i++;
			j++;
			if (j == p.size()) {
				idx.push_back(i - (p.size() - 1));
				j = table[j - 1] + 1;
			}
		}
		else if (j > 1) {
			j = table[j - 1] + 1;
		}
		else {
			i++;
		}
	}
}
int main() {
	FAST_IO;
	string tmp;
	getline(cin, tmp);
	t += tmp;
	getline(cin, tmp);
	p += tmp;
	table = vector<int>(p.size());
	kmp();
	cout << idx.size()<<'\n';
	for (int& i : idx) cout << i << ' ';
}