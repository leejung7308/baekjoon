//#include<bits/stdc++.h>
//using namespace std;
//void print(vector<vector<int>> mp) {
//	for (int i = 0; i < mp.size(); i++) {
//		for (int j = 0; j < mp[i].size(); j++) {
//			cout << mp[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int n, second = 0, d = 0;
//	cin >> n;
//	vector<vector<int>> mp(n + 2, vector<int>(n + 2));
//	for (int i = 0; i < n + 2; i++) {
//		for (int j = 0; j < n + 2; j++) {
//			if (i == 0 || j == 0 || i == n + 1 || j == n + 1)mp[i][j] = 1;
//		}
//	}
//	vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
//	int a;
//	cin >> a;
//	for (int i = 0; i < a; i++) {
//		int y, x;
//		cin >> y >> x;
//		mp[y][x] = 2;
//	}
//	int c;
//	cin >> c;
//	queue<pair<int, char>> change;
//	for (int i = 0; i < c; i++) {
//		int sec;
//		char direction;
//		cin >> sec >> direction;
//		change.push({ sec,direction });
//	}
//	queue<pair<int, int>> snake;
//	pair<int, int> curPos = { 1,1 };
//	mp[1][1] = 1;
//	snake.push(curPos);
//	while (true) {
//		second++;
//		//cout << "sec: " << second << " dir: "<< d <<'\n';
//		curPos = { curPos.first + dir[d].first, curPos.second + dir[d].second };
//		if (mp[curPos.first][curPos.second] == 1) {
//			cout << second;
//			break;
//		}
//		snake.push(curPos);
//		if (mp[curPos.first][curPos.second] != 2){
//			mp[snake.front().first][snake.front().second] = 0;
//			snake.pop();
//		}
//		mp[curPos.first][curPos.second] = 1;
//		if (!change.empty() && change.front().first == second) {
//			if (change.front().second == 'D') d = (d + 1) % 4;
//			else d -= 1;
//			d = d < 0 ? d + 4 : d;
//			change.pop();
//		}
//		//print(mp);
//	}
//}