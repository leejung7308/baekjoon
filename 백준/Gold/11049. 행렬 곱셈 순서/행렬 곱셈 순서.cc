#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

int N;
pair<int, int> matrix[501];
int dp[501][501];
pair<int, int> dp_matrix[501][501];

int Sum(int dx, int mid, int dy) {
	return dp_matrix[dx][mid].first * dp_matrix[dx][mid].second * dp_matrix[mid + 1][dy].second;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> matrix[i].first >> matrix[i].second;
		dp_matrix[i][i] = matrix[i];
	}
	for (int i = 1; i < N; i++) {
		for (int dx = 1; dx + i <= N; dx++) {
			int dy = dx + i;
			dp[dx][dy] = 2147483647;
			for (int mid = dx; mid < dy; mid++) {
				dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + Sum(dx, mid, dy));
			}
			dp_matrix[dx][dy].first = matrix[dx].first;
			dp_matrix[dx][dy].second = matrix[dy].second;
		}
	}
	cout << dp[1][N];
	return 0;
}