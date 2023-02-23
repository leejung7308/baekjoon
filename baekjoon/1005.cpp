//#include<stdio.h>
//#include<string.h>
//typedef struct BUILDING {
//	int num;
//	int delay;
//	int to_come[1001];
//	int flag;
//	int time;
//}building;
//building arr[1001] = { 0 };
//int is_visit[1001] = { 0 };
//int search(building start) {
//	if (start.flag==0) {
//		arr[start.num].time = start.delay;
//		is_visit[start.num] = 1;
//		return arr[start.num].time;
//	}
//	for (int i = 1; i < 1001; i++)
//	{
//		if (start.to_come[i]) {
//			int tmp;
//			if (is_visit[i]) tmp = arr[i].time;
//			else tmp = search(arr[i]);
//			if (arr[start.num].time < tmp) {
//				arr[start.num].time = tmp;
//			}
//		}
//	}
//	arr[start.num].time += start.delay;
//	is_visit[start.num] = 1;
//	return arr[start.num].time;
//}
//int main() {
//	int t, n, k, x, y, w;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%d %d", &n, &k);
//		for (int j = 1; j < n+1; j++)
//		{
//			arr[j].num = j;
//		}
//		for (int j = 1; j < n+1; j++)
//		{
//			scanf("%d", &arr[j].delay);
//		}
//		for (int j = 0; j < k; j++)
//		{
//			scanf("%d %d", &x, &y);
//			arr[y].to_come[x] = 1;
//			arr[y].flag = 1;
//		}
//		scanf("%d", &w);
//		printf("%d\n", search(arr[w]));
//		memset(arr, 0, sizeof(arr));
//		memset(is_visit, 0, sizeof(is_visit));
//	}
//}