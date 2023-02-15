//#include<stdio.h>
//int main() {
//	long long k, n, a[10000] = { 0 }, min = 1, max = 1, mid, cnt = 0, res;
//	scanf("%lld %lld", &k, &n);
//	for (int i = 0; i < k; i++)
//	{
//		scanf("%lld", &a[i]);
//		if (max < a[i]) max = a[i];
//	}
//	while (min<=max) {
//		mid = (max + min) / 2;
//		for (int i = 0; i < k; i++)
//		{
//			cnt += a[i] / mid;
//		}
//		if (cnt >= n) {
//			min = mid + 1;
//			res = mid;
//		}
//		else max = mid - 1;
//		cnt = 0;
//		//printf("%d %d %d\n", min, max, mid);
//	}
//	printf("%d", res);
//}