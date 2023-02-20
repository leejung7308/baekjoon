//#include<stdio.h>
//#include<stdlib.h>
//int cmp(const void* a, const void* b) {
//	return(*(int*)a - *(int*)b);
//}
//int main() {
//	int n, m, mid=0;
//	unsigned long long sum = 0;
//	scanf("%d %d", &n, &m);
//	int* tree = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &tree[i]);
//	}
//	qsort(tree, n, sizeof(int), cmp);
//	int min = 0, max = tree[n-1];
//	while (min <= max) {
//		mid = (min + max) / 2;
//		for (int i = 0; i < n; i++)
//		{
//			if (tree[i] - mid < 0) continue;
//			sum += tree[i] - mid;
//		}
//		if (sum < m) max = mid - 1;
//		else if (sum > m) min = mid + 1;
//		else break;
//		if (min > max && sum<m) mid--;
//		sum = 0;
//	}
//	printf("%d", mid);
//}