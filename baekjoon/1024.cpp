//#include<stdio.h>
//int main() {
//	int x, n, l;
//	scanf("%d %d", &n, &l);
//	
//	for (int i = l; i <= 100; i++) {
//		x = n;
//		x *= 2;
//		if (x % i == 0) {
//			x /= i;
//			if(x+1-i>=0){
//				x += 1 - i;
//				if (x % 2 == 0) {
//					x /= 2;
//					for (int k = 0; k < i; k++) {
//						printf("%d ", x++);
//					}
//					break;
//				}
//			}
//		}
//		if (i == 100) printf("-1");
//	}
//}