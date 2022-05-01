#include <stdio.h>
void swap(int *px, int *py);

int main(void) {
	int a = 100, b = 200;

	printf("swap() 호출전 a=%d b=%d\n", a, b);
	swap(&a, &b);	//변수 a와 b의 주소를 swap 함수로 전달.
	printf("swap() 호출후 a=%d b=%d\n", a, b);

	return 0;
}

void swap(int *px, int *py) {
	int temp;		//값을 임시로 저장할 변수 선언.

	temp = *py;		//포인터 py가 가리키는 값을 변수 temp에 저장.
	*py = *px;		//포인터 px가 가리키는 값을 포인터 py에 저장된 주소에 저장.
	*px = temp;		//temp 값을 포인터 px에 저장된 주소에 저장.
}