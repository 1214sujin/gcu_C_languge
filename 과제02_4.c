#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_int();
int is_prime(int n);

int get_int() {
	int n;
	printf("���� �ϳ��� �Է��Ͻÿ�: ");
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
		printf("�Ҽ��Դϴ�.");
	else
		printf("�Ҽ��� �ƴմϴ�.");
	return 0;
}