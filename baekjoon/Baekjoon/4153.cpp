//#include<stdio.h>
//int main() {
//	int a[3] = { 0 };
//	while (1) {
//		scanf("%d %d %d", &a[0], &a[1], &a[2]);
//		if (a[0] == 0) return 0;
//		for (int i = 0; i < 3; i++) {
//			for (int j = 0; j < 2 - i; j++) {
//				if (a[j] > a[j + 1]) {
//					int tmp = a[j];
//					a[j] = a[j + 1];
//					a[j + 1] = tmp;
//				}
//			}
//		}
//		if (a[0]*a[0]+a[1]*a[1]==a[2]*a[2]) printf("right\n");
//		else printf("wrong\n");
//	}
//}