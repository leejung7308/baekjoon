//#include<stdio.h>
//int main() {
//	int n, m, a, cnt = 0, res = 0;
//	int q[51] = { 0 }, tmp[51] = { 0 };
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++) q[i] = i + 1;
//	for (int i = 0; i < m; i++) {
//		scanf("%d", &a);
//		for (int j = 0; j < n; j++) {
//			if (q[j] == a) {
//				if (cnt > n - cnt) res += n - cnt;
//				else res += cnt;
//				n--;
//				break;
//			}
//			else cnt++;
//		}
//		for (int k = 0; k < cnt; k++) tmp[n - cnt + k] = q[k];
//		for (int k = cnt + 1; k < n + 1; k++) tmp[k - cnt - 1] = q[k];
//		for (int k = 0; k < n; k++) {
//			q[k] = tmp[k];
//		}
//		for (int k = 0; k < n; k++) tmp[k] = 0;
//		cnt = 0;
//	}
//	printf("%d", res);
//}