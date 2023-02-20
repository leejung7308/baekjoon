//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int cmp(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}
//int main() {
//	int n, cnt = 0, tmp = 1, res = 0, mid, diff, mode[8001] = { 0 };
//	double sum = 0, avg;
//	scanf("%d", &n);
//	int* a = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//		sum += a[i];
//	}
//	qsort(a, n, sizeof(int), cmp);
//	avg = sum / n;
//	if (avg<0 && avg>-1) avg = 0;
//	mid = (n - 1) / 2;
//	diff = a[n - 1] - a[0];
//	printf("%.0lf\n", avg);
//	printf("%d\n", a[mid]);
//	for (int i = 0; i < n; i++)
//	{
//		mode[a[i]+4000]++;
//	}
//	int max = 0;
//	for (int i = 0; i < 8001; i++)
//	{
//		if (mode[i] > max) max = mode[i];
//	}
//	for (int i = 0; i < 8001; i++)
//	{
//		if (mode[i] == max) {
//			res = i - 4000;
//			cnt++;
//		}
//		if (cnt == 2) break;
//	}
//	if (n == 1) res = a[0];
//	printf("%d\n", res);
//	printf("%d\n", diff);
//}