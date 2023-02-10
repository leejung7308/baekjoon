//#include<stdio.h>
//int main() {
//	int n, m, arr[51][51] = { 0 },size = 1;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%1d", &arr[i][j]);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			for (int k = j+1; k < m; k++) {
//				if (arr[i][j] == arr[i][k]) {
//					int s = k - j;
//					if (i + s >= n) break;
//					if (arr[i][j] == arr[i + s][j] && arr[i][j] == arr[i+s][j + s]) {
//						s++;
//						if (size < s * s) size = s * s;
//					}
//				}
//			}
//		}
//	}
//	printf("%d", size);
//}