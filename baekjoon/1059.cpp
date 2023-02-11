//#include<stdio.h>
//int main() {
//	int l, a[51] = { 0 }, n, min=0, max=0;
//	scanf("%d", &l);
//	for (int i = 0; i < l; i++) scanf("%d", &a[i]);
//	scanf("%d", &n);
//	for (int i = 0; i < l; i++)
//		if (a[i] == n) {
//			printf("0");
//			return 0;
//		}
//	for (int i = 0; i < l; i++) {
//		for (int j = 0; j < l - i - 1; j++) {
//			if (a[j] > a[j + 1]) {
//				int tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//	if (n < a[0]) {
//		printf("%d", (n - 1) * (a[0] - n) + (a[0] - n - 1));
//		return 0;
//	}
//	for (int i = 0; i < n - 1; i++) {
//		if (n >= a[i] && n <= a[i + 1]) {
//			min = a[i] + 1;
//			max = a[i + 1] - 1;
//			break;
//		}
//	}
//	int res = (n - min) * (max - n + 1) + (max - n);
//	printf("%d", res);
//}