#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int p, n, m;
	cin >> p;
	while (p--) {
		cin >> n >> m;
		int cnt = 0, a = 0, b = 1;
		do {
			int tmp = a;
			a = b;
			b = (tmp + a) % m;
			cnt++;
		} while (!(a == 0 && b == 1));
		cout << n << ' ' << cnt << '\n';
	}
}