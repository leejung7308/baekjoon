//#include<stdio.h>
//int main() {
//	int n;
//	char a[51][51];
//	int t[51][51] = { 0 };
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++){
//		scanf("%s", a[i]);
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++){
//			if (a[i][j] == 'Y') {
//				t[i][j] = 1;
//				for (int k = 0; k < n; k++) {
//					if (k == i) continue;
//					if (a[j][k] == 'Y') t[i][k] = 1;
//				}
//			}
//		}
//	}
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		int cnt = 0;
//		for (int j = 0; j < n; j++) {
//			if (t[i][j] == 1) cnt++;
//		}
//		if (cnt > max) max = cnt;
//	}
//	printf("%d", max);
//}