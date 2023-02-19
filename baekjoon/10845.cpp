//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main() {
//	int que[20000] = { 0 };
//	int f = 0, b = 0;
//	int n, num = 0;
//	char a[10];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%s", a);
//		if (strcmp(a, "push") == 0) {
//			scanf("%d", &num);
//			que[b++] = num;
//		}
//		else if (strcmp(a, "pop") == 0) {
//			if (f == b) printf("-1\n");
//			else printf("%d\n", que[f++]);
//		}
//		else if (strcmp(a, "size") == 0) {
//			printf("%d\n", b - f);
//		}
//		else if (strcmp(a, "empty") == 0) {
//			if (f == b) printf("1\n");
//			else printf("0\n");
//		}
//		else if (strcmp(a, "front") == 0) {
//			if (f == b) printf("-1\n");
//			else printf("%d\n", que[f]);
//		}
//		else if (strcmp(a, "back") == 0) {
//			if (f == b) printf("-1\n");
//			else printf("%d\n", que[b-1]);
//		}
//	}
//}