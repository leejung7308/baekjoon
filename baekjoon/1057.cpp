//#include<stdio.h>
//int main() {
//	int n, k, i;
//	scanf("%d %d %d", &n, &k, &i);
//	if (k > i) {
//		int tmp = k;
//		k = i;
//		i = tmp;
//	}
//	if (k % 2 == 1 && i == k + 1) printf("1");
//	else {
//		int cnt = 1;
//		while (1) {
//			if (k % 2 == 1) {
//				k = k / 2 + 1;
//				if (i % 2 == 1) i = i / 2 + 1;
//				else i /= 2;
//				cnt++;
//			}
//			else {
//				k /= 2;
//				if (i % 2 == 1) i = i / 2 + 1;
//				else i /= 2;
//				cnt++;
//			}
//			if (k % 2 == 1 && i == k + 1) {
//				printf("%d", cnt);
//				break;
//			}
//		}
//	}
//}