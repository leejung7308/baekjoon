#include<iostream>
#include<algorithm>
using namespace std;
void seek(int);
bool** dp;
bool* visited;
int com = 1;
int ans = 0;
int main() {
	int net;
	cin >> com >> net;
	com++;
	dp = new bool* [com];
	for (int i = 0; i < com; i++) {
		dp[i] = new bool[com];
		for (int j = 0; j < com; j++) {
			dp[i][j] = false;
		}
	}
	visited = new bool[com];
	for (int i = 0; i < com; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < net; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		dp[tmp1][tmp2] = true;
		dp[tmp2][tmp1] = true;
	}
	visited[1] = true;
	for (int i = 0; i < com; i++) {
		if (dp[1][i] == true && visited[i] == false) {
			visited[i] = true;
			ans++;
			seek(i);
		}
	}
	cout << ans;
	return 0;
}
void seek(int i) {
	for (int j = 0; j < com; j++) {
		if (dp[i][j] == true) {
			if (visited[j] == true) continue;
			else {
				visited[j] = true;
				ans++;
				seek(j);
			}
		}
	}
}