//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	char str[101],res[101];
//	int ans = 1,index=0;
//	while (1) {
//		scanf("%[^\n]s", str);
//		getchar();
//		if (str[0] == '.') break;
//		for (int i = 0; i < 100; i++)
//		{
//			if (str[i] == '.') break;
//			if (str[i] == '(') res[index++] = '(';
//			else if (str[i] == ')') {
//				if (res[index - 1] == '(') index--;
//				else {
//					ans = 0;
//					break;
//				}
//
//			}
//			if (str[i] == '[') res[index++] = '[';
//			else if (str[i] == ']') {
//				if (res[index - 1] == '[') index--;
//				else {
//					ans = 0;
//					break;
//				}
//			}
//		}
//		if (ans == 0) printf("no\n");
//		else if (index == 0 && ans) printf("yes\n");
//		else printf("no\n");
//		index = 0;
//		ans = 1;
//	}
//}