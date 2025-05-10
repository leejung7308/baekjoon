#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<int> seg(2097152);
void update(int s, int e, int n, int idx, int diff) {
	if (idx < s || e < idx) return;
	seg[n] += diff;
	if (s == e) return;
	int mid = (s + e) / 2;
	update(s, mid, n * 2, idx, diff);
	update(mid + 1, e, n * 2 + 1, idx, diff);
}
int search(int s, int e, int n, int p) {
	if (seg[n] < p) return seg[n];
	if (s == e) return -s;
	int mid = (s + e) / 2;
	int f = search(s, mid, n * 2, p), b = 0;
	if (f < 0) return f;
	if (f < p) b = search(mid + 1, e, n * 2 + 1, p - f);
	if (b < 0) return b;
	return 0;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	while (n--) {
		int a, b, c = 0;
		cin >> a >> b;
		if (a == 1) {
			int output = -search(1, 1000000, 1, b);
			cout << output << '\n';
			update(1, 1000000, 1, output, -1);
		}
		else {
			cin >> c;
			update(1, 1000000, 1, b, c);
		}
	}
}