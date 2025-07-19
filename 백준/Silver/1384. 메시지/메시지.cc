#include <iostream>
using namespace std;

string kid[21][21]; // 메시지가 적힌 종이
int kidNum[21] = {0};

// 나쁜 말을 쓴 아이와 나쁜 말을 적힌 종이를 받은 아이 출력
void print(int n, bool &isN) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (kid[i][j] == "N") {
				isN = true;

				// 나쁜 말을 쓴 아이 찾기
				int k = kidNum[j];
				if (i != 0)
					k = kidNum[(j - i + n) % n];

				printf("%s was nasty about %s\n", kid[k][0].c_str(), kid[i][0].c_str());
			}
		}
	}
}

int main() {
	int group = 1; // 그룹 번호

	while (true) {
		// 아이들의 수 n
		int n;
		cin >> n;

		// 0이 입력되면 종료
		if (n == 0) break;

		// 입력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> kid[i][j];

				if (i != 0)
					kidNum[i] = n - i;
			}
		}

		bool isN = false; // 나쁜 말을 한 아이가 있는가?

		// 그룹 번호 출력
		printf("Group %d\n", group++);

		print(n, isN);

		if (isN == false) // 모두 예쁜 말만 했을 때
			printf("Nobody was nasty\n");

		printf("\n");
	}

	return 0;
}