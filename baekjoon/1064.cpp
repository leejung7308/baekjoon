//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//int main() {
//	double xa, xb, xc, ya, yb, yc;
//	scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
//	double i=xb-xa, j=yb-ya, k=xc-xa, l=yc-ya;
//	if ((i == 0 && k == 0) || (j == 0 && l == 0)) {
//		printf("-1.0");
//		return 0;
//	}
//	else if (i > 0 && i > k && i / k == j / l) {
//		printf("-1.0");
//		return 0;
//	}
//	else if (i > 0 && i < k && k / i == l / j) {
//		printf("-1.0");
//		return 0;
//	}
//	else if (i < 0 && i > k && k / i == l / j) {
//		printf("-1.0");
//		return 0;
//	}
//	else if (i < 0 && i < k && i / k == j / l) {
//		printf("-1.0");
//		return 0;
//	}
//
//	double a=0, b=0, c=0;
//	a = sqrt(pow(yb - ya, 2) + pow(xb - xa, 2));
//	b = sqrt(pow(yc - yb, 2) + pow(xc - xb, 2));
//	c = sqrt(pow(yc - ya, 2) + pow(xc - xa, 2));
//	double sum[3] = {};
//	sum[0] = 2 * a + 2 * b;
//	sum[1] = 2 * b + 2 * c;
//	sum[2] = 2 * a + 2 * c;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2-i; j++)
//		{
//			if (sum[j] > sum[j + 1]) {
//				double tmp = sum[j];
//				sum[j] = sum[j + 1];
//				sum[j + 1] = tmp;
//			}
//		}
//	}
//	printf("%.10lf", sum[2] - sum[0]);
//}