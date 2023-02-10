#include<stdio.h>
int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	
	for (int i = l; i <= 100; i++) {
		int x = n;
		x *= 2;
		if (n % i == 0) {
			x /= i;
			x += 1 - i;
			if (x % 2 == 0) {
				x /= 2;
				for (int k = 0; k < i; k++) {
					printf("%d ", x++);
				}
				break;
			}
		}
	}
}