#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int ans = 0, n;
vector<int> v(100000);
int dnc(int s, int e) {
	if (s == e) return v[s];
	int mid = (s + e) / 2;
	int left = dnc(s, mid);
	int right = dnc(mid + 1, e);
	int front = mid, back = mid + 1;
	int minh = min(v[front], v[back]);
	int ret = minh * 2;
	while (!(front == s && back == e)) {
		if (front == s) back++;
		else if (back == e) front--;
		else if (v[back + 1] > v[front - 1]) back++;
		else front--;
		minh = min({ minh, v[front], v[back] });
		ret = max(ret, minh * (back - front + 1));
	}
	return max({ ret,left,right });
}
int main() {
	FAST_IO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << dnc(0, n - 1);
}