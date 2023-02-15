//#include<stdio.h>
//#include<stdlib.h>
//int cmp(const void* a, const void* b) {
//	int c = *(int*)a;
//	int d = *(int*)b;
//	if (c > d) return 1;
//	else if (c < d) return -1;
//	else return 0;
//}
//int main() {
//	int n, a[100000], m, b, check=0,min=0,max=0,mid;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	max = n-1;
//	qsort(a, n, sizeof(int), cmp);
//	scanf("%d", &m);
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &b);
//		while (min <= max) {
//			mid = (min + max) / 2;
//			if (b == a[mid]) {
//				check = 1;
//				break;
//			}
//			if (b > a[mid]) min = mid + 1;
//			if (b < a[mid]) max = mid - 1;
//		}
//		if (check) printf("1\n");
//		else  printf("0\n");
//		check = 0;
//		min = 0;
//		max = n-1;
//	}
//}