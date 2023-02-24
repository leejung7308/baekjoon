//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//typedef struct Vector {
//	int x;
//	int y;
//}vector;
//vector arr[20] = { 0 };
//int visited[20] = { 0 };
//int n;
//double sum = 20000000;
//double vsum() {
//	double xsum=0, ysum=0;
//	for (int i = 0; i < n; i++)
//	{
//		if (visited[i]) {
//			xsum -= arr[i].x;
//			ysum -= arr[i].y;
//		}
//		else {
//			xsum += arr[i].x;
//			ysum += arr[i].y;
//		}
//	}
//	return sqrt(pow(xsum, 2) + pow(ysum, 2));
//}
//void dfs(int now, int cnt) {
//	if (cnt == n / 2) {
//		double tmp = vsum();
//		if (tmp < sum) sum = tmp;
//	}
//	else {
//		for (int i = now; i < n; i++)
//		{
//			visited[i] = 1;
//			dfs(i + 1, cnt + 1);
//			visited[i] = 0;
//		}
//	}
//}
//int main() {
//	int t, x, y;
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		memset(visited, 0, sizeof(visited));
//		memset(arr, 0, sizeof(arr));
//		sum = 20000000;
//		scanf("%d", &n);
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d %d", &arr[j].x, &arr[j].y);
//		}
//		dfs(0, 0);
//		printf("%.7lf\n", sum);
//	}
//
//}