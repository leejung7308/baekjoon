#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
	int n, m, k;
	int map[11][11]; // 현재 땅의 양분 값, 처음엔 전부 5
	int A[11][11]; // 겨울에 주입할 양분 값
	// 살아있는 나무 정보 <나무가 존재하는 좌표 위치, 해당 좌표 나무들 나이 모음>
	std::map<pair<int, int>, vector<int>> alive_pos;

	// 각종 입력 받기
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> A[i][j];
	}
	for(int i = 0; i < m; ++i){ // 나무 입력 받기
		int x, y, age;
		cin >> x >> y >> age; x--; y--;
		alive_pos[{x, y}].push_back(age); // 해당 좌표에 나무 나이 추가
	}
	fill(map[0], map[0] + 11 * 11, 5); // 전부 5로 채워주기

	for(int i = 0; i < k; ++i){ // k 해만큼 반복
		// 4계절 반복, 0 == 봄, 여름 1 == 가을 2 == 겨울
		for(int j = 0; j < 3; ++j){
			if (j == 0) { // 봄이면
				// 살아 있는 각 나무 정보를 불러와
				for(auto& [pos, age] : alive_pos){
					vector<int> new_age; // 복사용 배열
					int dead_nut = 0; // 죽은 나무가 주는 양분 합산
					// 먼저 나이값 기준 오름차순 정렬
					sort(age.begin(), age.end());
					// 가장 어린 나무부터 양분 먹이기 시도
					for(int o = 0; o < age.size(); ++o){
						// 먹일 수 있으면
						if (map[pos.X][pos.Y] - age[o] >= 0){
							// 복사용 배열에 한살 더 먹은 나무 추가
							new_age.push_back(age[o] + 1);
							map[pos.X][pos.Y] -= age[o]; // 양분 감소
						}
						// 먹일 수 없으면 나이 / 2 를 dead_nut에 더해줌
						else dead_nut += age[o] / 2;
					}
					alive_pos[{pos.X, pos.Y}] = new_age; // 복사용 배열 대입하고
					map[pos.X][pos.Y] += dead_nut; // 죽은 나무가 주는 양분을 바로 더해줘 여름 대체
				}
			}
			if (j == 1) { // 가을이면
				// 8방향 탐색용 배열
				int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
				int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};
				// 살아 있는 각 나무 정보를 불러와
				for(auto& [pos, age] : alive_pos){
					// 나이를 순회하며
					for(int o = 0; o < age.size(); ++o){
						if (age[o] % 5 == 0) { // 5의 배수이면
							// 8방향 순회하며 번식
							for(int dir = 0; dir < 8; ++dir){
								int nx = pos.X + dx[dir];
								int ny = pos.Y + dy[dir];
								if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

								alive_pos[{nx, ny}].push_back(1); // 1살 나무 추가
							}
						}
					}
				}
			}
			if (j == 2) { // 겨울이면
				// S2D2가 각 칸에 양분 추가
				for(int o = 0; o < n; ++o){
					for(int p = 0; p < n; ++p)
						map[o][p] += A[o][p];
				}
			}
		}
	}

	// 살아있는 나무 갯수 구하기
	int cnt = 0;
	for(auto& [pos, age] : alive_pos){
		// pos.second = 나무 벡터, 나무 벡터의 사이즈를 카운터에 더해줌
		cnt += age.size();
	}

	cout << cnt << endl;

	return 0;
}