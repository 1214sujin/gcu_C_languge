#include <stdio.h>
void swap(int *px, int *py);

int main(void) {
	int a = 100, b = 200;

	printf("swap() ȣ���� a=%d b=%d\n", a, b);
	swap(&a, &b);	//���� a�� b�� �ּҸ� swap �Լ��� ����.
	printf("swap() ȣ���� a=%d b=%d\n", a, b);

	return 0;
}

void swap(int *px, int *py) {
	int temp;		//���� �ӽ÷� ������ ���� ����.

	temp = *py;		//������ py�� ����Ű�� ���� ���� temp�� ����.
	*py = *px;		//������ px�� ����Ű�� ���� ������ py�� ����� �ּҿ� ����.
	*px = temp;		//temp ���� ������ px�� ����� �ּҿ� ����.
}