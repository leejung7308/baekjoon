#include<stdio.h>
int main() {
	int t, m, n, k;
	int x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int cnt = 0;
		int area[52][52] = { 0 };
		int check[52][52] = { 0 };
		scanf("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d %d", &x, &y);
			area[x+1][y+1] = 1;
		}
		for (int a = 1; a <= m; a++) {
			for (int b = 1; b <= n; b++) {
				if (area[a][b] == 1) {
					check[a][b] = 1;
					if (check[a + 1][b] == 1) continue;
					else if (check[a - 1][b] == 1) continue;
					else if (check[a][b + 1] == 1) continue;
					else if (check[a][b - 1] == 1) continue;
					else cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}