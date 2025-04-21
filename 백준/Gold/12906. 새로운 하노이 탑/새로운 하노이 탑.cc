#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
vector<string> split(const string& s) {
	int idx = 0;
	vector<string> ret(3);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/') {
			idx++;
			continue;
		}
		ret[idx] += s[i];
	}
	return ret;
}
string make(const vector<string>& v, int start, int end, int maintain) {
	if (v[start].size() == 0) return "";
	string s = v[start], e = v[end], m = v[maintain];
	e += s.back();
	s.pop_back();
	vector<string> tmp(3);
	tmp[start] = s;
	tmp[end] = e;
	tmp[maintain] = m;
	string ret;
	for (int i = 0; i < 3; i++) {
		ret += tmp[i];
		ret += '/';
	}
	return ret;
}
bool isvalid(const string& s) {
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '/') {
			idx++;
			continue;
		}
		if (s[i] != idx + 'A') return false;
	}
	return true;
}
int main() {
	FAST_IO;
	string cur;
	unordered_map<string, bool> visited;
	for (int i = 0; i < 3; i++) {
		int n;
		cin >> n;
		string tmp;
		if (n != 0) {
			cin >> tmp;
			cur += tmp;
		}
		cur += '/';
	}
	if (isvalid(cur)) {
		cout << 0;
		return 0;
	}
	queue<pair<int, string>> q;
	q.push({ 0,cur });
	visited[cur] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		vector<string> cur = split(q.front().second);
		q.pop();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				for (int k = 0; k < 3; k++) {
					if (k == i || k == j) continue;
					string next = make(cur, i, j, k);
					if (next == "") continue;
					if (visited.find(next) != visited.end()) continue;
					if (isvalid(next)) {
						cout << cnt + 1;
						return 0;
					}
					visited[next] = true;
					q.push({ cnt + 1,next });
				}
			}
		}
	}
}