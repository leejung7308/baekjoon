//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int n, k;
//	scanf("%d %d", &n, &k);
//	int cnt = n, flag = k-1, idx = 0;
//	int* a = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++) a[i] = i+1;
//	printf("<");
//	while (cnt != 0) {
//		if (flag == 0 && a[idx] != 0) {
//			if (cnt==1) printf("%d>", a[idx]);
//			else printf("%d, ", a[idx]);
//			a[idx] = 0;
//			flag = k-1;
//			cnt--;
//		}
//		else {
//			if (a[idx] != 0) flag--;
//			if (idx == n - 1) idx = 0;
//			else idx++;
//		}
//	}
//}