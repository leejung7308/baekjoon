//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int n, flag = 1, cnt = 0, tmp;
//	scanf("%d", &n);
//	if (n == 1) {
//		printf("1");
//		return 0;
//	}
//	int *a = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++){
//		a[i] = i+1;
//	}
//	while (1)
//	{
//		cnt = 0;
//		for (int i = 0; i < n; i++)
//		{
//			if (flag) {
//				if (a[i] != 0) {
//					a[i] = 0;
//					flag--;
//				}
//			}
//			else {
//				if (a[i] != 0) {
//					flag++;
//					cnt++;
//					tmp = i;
//				}
//			}
//		}
//		if (cnt == 1) break;
//	}
//	printf("%d", a[tmp]);
//}