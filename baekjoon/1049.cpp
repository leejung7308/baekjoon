//#include<stdio.h>
//int main() {
//	int n, m, minp=1000, mins=1000, p[51] = { 0 }, s[51] = { 0 } , a, b;
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < m; i++) scanf("%d %d", &p[i], &s[i]);
//	for (int i = 0; i < m; i++){
//		if (p[i] < minp) minp = p[i];
//		if (s[i] < mins) mins = s[i];
//	}
//	if (minp > mins * 6) printf("%d", mins * n);
//	else {
//		a = (n / 6 + 1) * minp;
//		b = n / 6 * minp + n % 6 * mins;
//		a < b ? printf("%d", a) : printf("%d", b);
//	}
//}