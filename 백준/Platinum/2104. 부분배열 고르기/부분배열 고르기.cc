#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define LLINF 9000000000000000000
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define DIR8 const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}}
#define MOD 1000000007
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
vector<LL> seg(400000), minseg(400000, 0);
vector<LL> v(100001,LLINF);
int n;
void update(int start, int end, int n, int idx, LL diff) {
	if (idx < start || end < idx) return;
	seg[n] += diff;
	if (v[minseg[n]] > diff) minseg[n] = idx;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, n * 2, idx, diff);
	update(mid + 1, end, n * 2 + 1, idx, diff);
}
LL gets(int start, int end, int n, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return seg[n];
	int mid = (start + end) / 2;
	return gets(start, mid, n * 2, left, right) + gets(mid + 1, end, n * 2 + 1, left, right);
}
LL getm(int start, int end, int n, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return minseg[n];
	int mid = (start + end) / 2;
	int lidx = getm(start, mid, n * 2, left, right);
	int ridx = getm(mid + 1, end, n * 2 + 1, left, right);
	if (v[lidx] < v[ridx]) return lidx;
	else return ridx;
}
LL getans(int start, int end) {
	if (end < start) return 0;
	if (start == end) return v[end] * v[end];
	int midx = getm(1, n, 1, start, end);
	LL ret = gets(1, n, 1, start, end) * v[midx];
	LL lv = getans(start, midx - 1);
	LL rv = getans(midx + 1, end);
	return max({ ret,lv,rv });
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		update(1, n, 1, i, v[i]);
	}
	cout << getans(1, n);
}