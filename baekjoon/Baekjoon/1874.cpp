//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main() {
//	int n,flag=0,no=0,id=0;
//	scanf("%d", &n);
//	int* a = (int*)malloc(sizeof(int) * n);
//	int* stack = (int*)malloc(sizeof(int) * n);
//	char* res = (char*)malloc(sizeof(char) * n * 2+1);
//	memset(stack, 0, sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//		if (no) continue;
//		if (i == 0) {
//			for (int j = 0; j < a[i]; j++)
//			{
//				stack[j]=1;
//				res[id++] = '+';
//				if (j == a[i] - 1) {
//					stack[j] = -1;
//					res[id++] = '-';
//				}
//			}
//		}
//		else if (a[i] > a[i - 1]) {
//			for (int j = a[i - 1]; j < a[i]; j++)
//			{
//				if (stack[j] == -1) continue;
//				stack[j]=1;
//				res[id++] = '+';
//				if (j == a[i] - 1) {
//					stack[j] = -1;
//					res[id++] = '-';
//				}
//			}
//		}
//		else if (a[i] < a[i - 1]) {
//			for (int j = a[i]; j < a[i - 1] - 1; j++)
//			{
//				if (stack[j] == 1) {
//					no = 1;
//					break;
//				}
//			}
//			if (no) continue;
//			else {
//				stack[a[i] - 1] = -1;
//				res[id++] = '-';
//			}
//		}
//	}
//	if (no) printf("NO");
//	else {
//		for (int i = 0; i < n*2; i++)
//		{
//			printf("%c\n", res[i]);
//		}
//	}
//}