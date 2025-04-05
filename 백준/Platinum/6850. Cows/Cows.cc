#include<bits/stdc++.h>
#include<unordered_map>
#include<math.h>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
pair<int, int> p0;
int ccw(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
	long long c = (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first);
	if (c > 0) return 1;
	if (c == 0) return 0;
	if (c < 0) return -1;
}
double distance(pair<int, int> p1, pair<int, int> p2) {
	return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second > b.second) return true;
	else if (a.second < b.second) return false;
	else if (a.first < b.first) return true;
	else return false;
}
bool cmp2(const pair<int, int>& a, const pair<int, int>& b) {
	int c = ccw(p0, a, b);
	if (c < 0) return true;
	if (c == 0) return distance(p0, a) < distance(p0, b);
	else return false;
}
double getarea(const pair<int, int>& p1, const pair<int, int>& p2, const pair<int, int>& p3) {
	double a = distance(p3, p2), b = distance(p1, p2), c = distance(p1, p3);
	double t = acos((b * b + c * c - a * a) / (2 * b * c));
	double h = b * sin(t);
	return 0.5 * h * c;
}
int main() {
	FAST_IO;
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), cmp);
	p0 = v[0];
	sort(v.begin() + 1, v.end(), cmp2);
	vector<int> st(n);
	int top = 1;
	st[0] = 0, st[1] = 1;
	for (int i = 2; i < v.size(); i++) {
		while (top >= 1 && ccw(v[st[top - 1]], v[st[top]], v[i]) >= 0) top--;
		st[++top] = i;
	}
	double area = 0;
	for (int i = 2; i <= top; i++) area += getarea(v[st[0]], v[st[i]], v[st[i - 1]]);
	cout << (int)area / 50;
}