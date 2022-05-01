#include <stdio.h>

int main(void) {
	double pi = 3, bunmo = 3, bunja = 4, bm;
	for (int i = 0; i < 100; i++) {
		bm = (bunmo - 1) * bunmo * (bunmo + 1);
		pi += bunja / bm;
		bunmo += 2;
		bunja = -bunja;
	}
	printf("%lf", pi);
	return 0;
}