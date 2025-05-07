#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	long long s, b;
	cin >> s >> b;
	vector<bool> visited(1000021);
	long long ans = b - s + 1;
	for (long long i = 2; i * i <= b; i++) {
		long long ret = s / (i * i);
		if (s % (i * i) != 0) ret++;
		for (; ret * i * i <= b; ret++) {
			if (visited[ret * i * i - s]) continue;
			visited[ret * i * i - s] = true;
			ans--;
		}
	}
	cout << ans;
}