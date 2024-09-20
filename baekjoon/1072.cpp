//#include<stdio.h>
//int main() {
//	long long x, y, z;
//	scanf("%lld %lld", &x, &y);
//	z = y * 100 / x;
//	long long min = y, max = 3000000000, mid, tmp;
//	while (min <= max) {
//		mid = (min + max) / 2;
//		tmp = mid * 100 / (x + mid - y);
//		if (tmp > z) max = mid - 1;
//		else if (tmp <= z) min = mid + 1;
//	}
//	tmp = min * 100 / (x + min - y);
//	if (tmp == z) printf("-1");
//	else printf("%lld", min - y);
//}