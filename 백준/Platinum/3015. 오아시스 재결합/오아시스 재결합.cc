#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000001
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
int main() {
	FAST_IO;
	int n;
	long long ans = 0;
	cin >> n;
	stack<pair<int,int>> st;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (!st.empty()) {
			if (st.top().first > tmp) ans++;
			else {
				while (!st.empty() && st.top().first < tmp) {
					ans += st.top().second;
					st.pop();
				}
				if (!st.empty()) {
					if (st.top().first > tmp) ans++;
					else if (st.size() > 1) ans += st.top().second + 1;
					else ans += st.top().second;
				}
			}
		}
		if (!st.empty() && st.top().first == tmp) st.top().second++;
		else st.push({ tmp,1 });
	}
	cout << ans;
}