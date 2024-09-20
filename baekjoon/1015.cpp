//#include<stdio.h>
//int main() {
//	int a[50] = { 0 }, p[50] = { 0 } , n;
//	int order = 0, min = 1001;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &a[i]);
//	}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++) if (a[j] < min) min = a[j];
//		for (int k = 0; k < n; k++) {
//			if (a[k] == min) {
//				p[k] = order++;
//				a[k] = 1001;
//				min = 1001;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) printf("%d ", p[i]);
//}