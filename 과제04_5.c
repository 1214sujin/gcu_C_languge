#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_int(int *px, int *py);

int main(void) {
	int x, y;

	get_int(&x, &y);	//x�� y�� �ּҸ� �Լ� get_int�� ����.
	printf("������ ���� %d \n", x + y);

	return 0;
}

void get_int(int *px, int *py) {
	printf("������ �� �� �Է��Ͻÿ�\n");
	scanf("%d", px);	//������ px�� ����� �ּҿ� �Է¹��� ���� ����.
	scanf("%d", py);	//������ py�� ����� �ּҿ� �Է¹��� ���� ����.
}