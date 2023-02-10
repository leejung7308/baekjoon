//#include<stdio.h>
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	if (n <= k) printf("0");
//	else {
//		int res = 0;
//		while (1) {
//			int cnt = 0;
//			int tmp = n;
//			while (tmp > 0) {
//				if (tmp % 2 == 0) tmp /= 2;
//				else {
//					tmp /= 2;
//					cnt++;
//				}
//			}
//			if (cnt <= k) break;
//			n++;
//			res++;
//		}
//		printf("%d", res);
//	}
//}