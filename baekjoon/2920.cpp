//#include<stdio.h>
//int main() {
//	int a[9] = { 0 };
//	for (int i = 0; i < 8; i++) scanf("%d", &a[i]);
//	if (a[0] == 1)
//	{
//		for (int i = 0; i < 8; i++)
//		{
//			if (a[i] != i + 1) {
//				printf("mixed");
//				return 0;
//			}
//		}
//		printf("ascending");
//	}
//	else if (a[0] == 8)
//	{
//		int k = 8;
//		for (int i = 0; i < 8; i++)
//		{
//			if (a[i] != k--) {
//				printf("mixed");
//				return 0;
//			}
//		}
//		printf("descending");
//	}
//	else printf("mixed");
//}