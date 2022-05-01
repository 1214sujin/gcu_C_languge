#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_int();
int is_prime(int n);

int get_int() {
	int n;
	printf("정수 하나를 입력하시오: ");
	scanf("%d", &n);
	return n;
}

int is_prime(int n) {
	int tf=1;
	if (n == 1)
		tf = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			tf = 0;
			break;
		}
	}
	return tf;
}

int main(void) {
	int n, tf;
	n = get_int();
	tf = is_prime(n);

	if (tf == 1)
		printf("소수입니다.");
	else
		printf("소수가 아닙니다.");
	return 0;
}