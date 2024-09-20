//#include<stdio.h>
//#include<math.h>
//int main() {
//	int l;
//	char a[51];
//	scanf("%d", &l);
//	scanf("%s", a);
//	long long sum = 0, m=1;
//	for (int i = 0; i < l; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			m *= 31;
//			m %= 1234567891;
//		}
//		sum += (a[i] - 'a' + 1) * m;
//		sum %= 1234567891;
//		m = 1;
//	}
//	printf("%lld", sum);
//}