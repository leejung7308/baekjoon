//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int cmp(const void* a, const void* b) {
//	if (strlen((char*)a) > strlen((char*)b)) return 1;
//	if (strlen((char*)a) < strlen((char*)b)) return -1;
//	if (strlen((char*)a) == strlen((char*)b)) return strcmp((char*)a, (char*)b);
//}
//int main() {
//	int n;
//	char tmp[51];
//	char w[20000][51];
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)	scanf("%s", w[i]);
//	
//	qsort(w, n, sizeof(w[0]), cmp);
//	for (int i = 0; i < n; i++) {
//		if (strcmp(w[i], w[i + 1]) != 0 || i == n - 1)	printf("%s\n", w[i]);
//	}
//}