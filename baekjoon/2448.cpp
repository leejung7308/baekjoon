//#include<bits/stdc++.h>
//#define INF 987654321
//using namespace std;
//vector<vector<char>> arr(3072, vector<char>(6144, ' '));
//void draw(int row, int col) {
//	arr[row][col] = '*';
//	arr[row + 1][col - 1] = '*';
//	arr[row + 1][col + 1] = '*';
//	for (int i = -2; i < 3; i++) {
//		arr[row + 2][col + i] = '*';
//	}
//}
//void getCorner(int len, int row, int col) {
//	if (len == 3) {
//		draw(row, col);
//		return;
//	}
//	getCorner(len / 2, row, col);
//	getCorner(len / 2, row + len / 2, col - len / 2);
//	getCorner(len / 2, row + len / 2, col + len / 2);
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n;
//	cin >> n;
//	getCorner(n, 0, n - 1);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < 2 * n - 1; j++) {
//			cout << arr[i][j];
//		}
//		cout << '\n';
//	}
//}