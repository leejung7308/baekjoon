//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main() {
//	int stack[10000] = {0};
//	int top = -1;
//	int n, num=0;
//	char a[10];
//	const char* push = "push";
//	const char* pop = "pop";
//	const char* size = "size";
//	const char* empty = "empty";
//	const char* Top = "top";
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", a);
//		if (strcmp(a, push) == 0) {
//			scanf("%d", &num);
//			stack[++top] = num;
//		}
//		else if (strcmp(a, pop) == 0) {
//			if (top < 0) printf("-1\n");
//			else printf("%d\n", stack[top--]);
//		}
//		else if (strcmp(a, size) == 0) {
//			printf("%d\n", top + 1);
//		}
//		else if (strcmp(a, empty) == 0) {
//			if (top < 0) printf("1\n");
//			else printf("0\n");
//		}
//		else if (strcmp(a, Top) == 0) {
//			if (top < 0) printf("-1\n");
//			else printf("%d\n", stack[top]);
//		}
//	}
//}