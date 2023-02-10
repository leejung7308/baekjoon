//#include<stdio.h>
//int sqrt(int a, int b) {
//	return a * a + b * b;
//}
//int main() {
//	int T, x1, y1, x2, y2, n, x, y, r, cnt=0;
//	scanf("%d", &T);
//	for(int j=0;j<T;j++){
//		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%d %d %d", &x, &y, &r);
//			if ((sqrt(x - x1, y - y1) < r * r) && (sqrt(x - x2, y - y2) > r * r)) {
//				cnt++;
//			}
//			else if ((sqrt(x - x1, y - y1) > r * r) && (sqrt(x - x2, y - y2) < r * r)) {
//				cnt++;
//			}
//		}
//		printf("%d\n", cnt);
//		cnt = 0;
//	}
//	return 0;
//}