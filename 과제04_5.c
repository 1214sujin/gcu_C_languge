#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_int(int *px, int *py);

int main(void) {
	int x, y;

	get_int(&x, &y);	//x와 y의 주소를 함수 get_int로 전달.
	printf("정수의 합은 %d \n", x + y);

	return 0;
}

void get_int(int *px, int *py) {
	printf("정수를 두 번 입력하시오\n");
	scanf("%d", px);	//포인터 px에 저장된 주소에 입력받은 값을 저장.
	scanf("%d", py);	//포인터 py에 저장된 주소에 입력받은 값을 저장.
}