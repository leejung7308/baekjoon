//#include<stdio.h>
//#include<stdlib.h>
//typedef struct TIME {
//	int time_e;
//	int time_b;
//	int block_e;
//	int block_b;
//}time;
//int main() {
//	int n, m, b, t = 0;
//	int cnt[257] = { 0 };
//	int a[500][500] = { 0 };
//	scanf("%d %d %d", &n, &m, &b);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &a[i][j]);
//			for (int k = 0; k < a[i][j] + 1; k++) cnt[k]++;
//		}
//	}
//	int high=-1,low;
//	int set = n * m;
//	for (int i = 0; i < 257; i++)
//	{
//		if (cnt[i] == set) low = i;
//		if (cnt[i] != set && cnt[i] != 0) high = i;
//	}
//	int stack = high - low;
//	time* arr = (time*)malloc(sizeof(time) * (stack));
//	for (int i = 0; i < stack; i++)
//	{
//		arr[i].time_e = 2 * cnt[low + 1 + i];
//		arr[i].time_b = set - cnt[low + 1 + i];
//		arr[i].block_e = cnt[low + 1 + i];
//		arr[i].block_b = set - cnt[low + 1 + i];
//	}
//	for (int i = 0; i < stack; i++)
//	{
//		if (arr[i].time_b <= arr[i].time_e) {
//			if (b >= arr[i].block_b) {
//				t += arr[i].time_b;
//				b -= arr[i].block_b;
//				low++;
//			}
//			else {
//				while (b < arr[i].block_b) {
//					t += arr[stack - 1].time_e;
//					b += arr[stack - 1].block_e;
//					stack--;
//					if (stack == i) {
//						printf("%d %d", t, low);
//						return 0;
//					}
//					if (stack - 1 == i && b < arr[i].block_b) {
//						t += arr[stack - 1].time_e;
//						b += arr[stack - 1].block_e;
//						printf("%d %d", t, low);
//						return 0;
//					}
//				}
//				t += arr[i].time_b;
//				b -= arr[i].block_b;
//				low++;
//			}
//		}
//		else {
//			t += arr[i].time_e;
//		}
//	}
//	printf("%d %d", t, low);
//}