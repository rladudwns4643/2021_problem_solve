#include <stdio.h> 

int main(void) {
	int cnt, h, w, n, i;
	scanf("%d", &cnt);
	for(i = 0; i < cnt; i++) {
		scanf("%d %d %d", &h, &w, &n);
		n % h == 0 ? printf("%d%02d\n", h, n / h) : printf("%d%02d\n", n % h, n / h + 1);
	}
}