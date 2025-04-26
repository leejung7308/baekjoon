#include<deque>
#include<iostream>
#include<string>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int n, l, tmp;
deque<pair<int, int>> dq;
string ans;
int main() {
	FAST_IO;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (!dq.empty() && dq.front().second < i - l + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first > tmp) dq.pop_back();
		dq.push_back({ tmp,i });
		ans += to_string(dq.front().first) + ' ';
	}
	cout << ans;
	return 0;
}