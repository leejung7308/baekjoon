//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int t,n,m;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		int cnt = 0;
//		scanf("%d %d", &n, &m);
//		int f = 0;
//		int* a = (int*)malloc(sizeof(int) * n);
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &a[j]);
//		}
//		while (1) {
//			int max = 0;
//			for (int j = 0; j < n; j++)
//			{
//				if (a[j] > max) max = a[j];
//			}
//			while (a[f] != max) {
//				f = (f + 1) % n;
//			}
//			a[f] = 0;
//			cnt++;
//			if (f == m || cnt == n) break;
//		}
//		printf("%d\n", cnt);
//	}
//
//}