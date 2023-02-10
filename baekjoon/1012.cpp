//#include<stdio.h>
//int m, n;
//int area[52][52] = { 0 };
//int cabbage(int a, int b) {
//	area[a][b] = 0;
//	if (area[a - 1][b] == 1) cabbage(a - 1, b);
//	if (area[a + 1][b] == 1) cabbage(a + 1, b);
//	if (area[a][b-1] == 1) cabbage(a, b-1);
//	if (area[a][b+1] == 1) cabbage(a, b+1);
//	return 0;
//}
//int main() {
//	int t, k;
//	int x, y;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++) {
//		int cnt = 0;
//		scanf("%d %d %d", &m, &n, &k);
//		for (int j = 0; j < k; j++) {
//			scanf("%d %d", &x, &y);
//			area[x+1][y+1] = 1;
//		}
//		for (int a = 1; a <= m; a++) {
//			for (int b = 1; b <= n; b++) {
//				if (area[a][b] == 1) {
//					cabbage(a, b);
//					cnt++;
//				}
//			}
//		}
//		printf("%d\n", cnt);
//		m = 0;
//		n = 0;
//	}
//}