//#include<stdio.h>
//#include<stdlib.h>
//typedef struct MEMBER{
//	int age;
//	char name[101];
//	int index;
//}mem;
//int cmp(const void* a, const void* b) {
//	mem A = *(mem*)a;
//	mem B = *(mem*)b;
//	if (A.age > B.age) return 1;
//	else if (A.age < B.age) return -1;
//	else {
//		if (A.index > B.index) return 1;
//		else if (A.index < B.index) return -1;
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	mem *a = (mem*)malloc(sizeof(mem) * n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d %s", &a[i].age, a[i].name);
//		a[i].index = i;
//	}
//	qsort(a, n, sizeof(mem), cmp);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d %s\n", a[i].age, a[i].name);
//	}
//}