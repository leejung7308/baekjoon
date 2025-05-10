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
	seg[n]--;
	if (s == e) return s;
	int mid = (s + e) / 2;
	if (seg[n * 2] >= p) return search(s, mid, n * 2, p);
	else return search(mid + 1, e, n * 2 + 1, p - seg[n * 2]);
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	while (n--) {
		int a, b, c = 0;
		cin >> a >> b;
		if (a == 1) {
			cout << search(1, 1000000, 1, b) << '\n';
		}
		else {
			cin >> c;
			update(1, 1000000, 1, b, c);
		}
	}
}