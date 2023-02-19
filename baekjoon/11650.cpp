//#include<stdio.h>
//#include<stdlib.h>
//typedef struct XY {
//	int x;
//	int y;
//}xy;
//int cmp(const void* a, const void* b) {
//	xy A = *(xy*)a;
//	xy B = *(xy*)b;
//	if (A.x > B.x) return 1;
//	else if (A.x < B.x) return -1;
//	else {
//		if (A.y > B.y)return 1;
//		else if (A.y < B.y)return -1;
//		else return 0;
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	xy* a = (xy*)malloc(sizeof(xy) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %d", &a[i].x, &a[i].y);
//	}
//	qsort(a, n, sizeof(xy), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %d\n", a[i].x, a[i].y);
//	}
//}