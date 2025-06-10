#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
#define LL long long
#define pii pair<int,int>
using namespace std;
const pii operator+(const pii& a, const pii& b) { return { a.first + b.first,a.second + b.second }; }
int main() {
	FAST_IO; 
	int n, ans = 0;
	cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back({ tmp,i });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) ans = max(ans, v[i].second - i);
	cout << ans + 1;
}