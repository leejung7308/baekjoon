//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int t, x, y;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%d %d", &x, &y);
//		int dis = y - x;
//		int min = 1, max = 47000;
//		int res;
//		while (min <= max) {
//			long long mid = (min + max) / 2;
//			if (mid * mid > dis) {
//				max = mid - 1;
//			}
//			else if (mid * mid < dis) min = mid + 1;
//			else {
//				res = mid;
//				break;
//			}
//			res = max;
//		}
//		int left = dis - res * res;
//		if (left == 0) printf("%d\n", 2 * res - 1);
//		else {
//			int tmp=0;
//			if (left % res != 0) tmp = 1;
//			printf("%d\n", 2 * res - 1 + left / res + tmp);
//		}
//	}
//}