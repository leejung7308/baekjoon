//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int a[500][500] = { 0 };
//	int n, m, b, t = 0, height=0;
//	scanf("%d %d %d", &n, &m, &b);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//	int min = 0;
//	for (int i = 0; i < 257; i++)
//	{
//		int tmp = b;
//		t = 0;
//		for (int j = 0; j < n; j++)
//		{
//			for (int k = 0; k < m; k++)
//			{
//				if (a[j][k] < i) {
//					tmp -= i - a[j][k];
//					t += i-a[j][k];
//				}
//				else if (a[j][k] > i) {
//					tmp += a[j][k] - i;
//					t += 2 * (a[j][k]-i);
//				}
//			}
//		}
//		if (tmp < 0) continue;
//		if (i == 0) {
//			min = t;
//			height = i;
//		}
//		else if (min >= t) {
//			min = t;
//			height = i;
//		}
//	}
//	printf("%d %d", min, height);
//}