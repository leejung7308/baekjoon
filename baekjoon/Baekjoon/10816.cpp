//#include<stdio.h>
//#include<stdlib.h>
//int cmp(const void* a, const void* b) {
//	return (*(int*)a - *(int*)b);
//}
//int main() {
//	int n, m, min, max, mid, cnt = 0, tmpu=0, tmpd=0, flag = 0;
//	scanf("%d", &n);
//	int* a = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	qsort(a, n, sizeof(int), cmp);
//	scanf("%d", &m);
//	int b;
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d", &b);
//		min = 0;
//		max = n - 1;
//		tmpu = 0;
//		tmpd = 0;
//		while (min <= max) {
//			flag = 0;
//			mid = (min + max) / 2;
//			if (a[mid] == b) {
//				flag = 1;
//				if (mid == 0) {
//					tmpd = 0;
//					break;
//				}
//				if (a[mid] == a[mid - 1]) {
//					max = mid - 1;
//				}
//				else {
//					tmpd = mid;
//					break;
//				}
//			}
//			else if (a[mid] < b) min = mid + 1;
//			else  max = mid - 1;
//		}
//		min = 0;
//		max = n - 1;
//		while (min <= max) {
//			flag = 0;
//			mid = (min + max) / 2;
//			if (a[mid] == b) {
//				flag = 1;
//				if (mid == n-1) {
//					tmpu = n-1;
//					break;
//				}
//				if (a[mid] == a[mid + 1]) {
//					min = mid + 1;
//				}
//				else {
//					tmpu = mid;
//					break;
//				}
//			}
//			else if (a[mid] < b) min = mid + 1;
//			else  max = mid - 1;
//		}
//		if (flag) printf("%d ", tmpu - tmpd + 1);
//		else printf("0 ");
//	}
//}