//분석만 하면 되므로 제출 불필요
#include <stdio.h>
void get_sum_diff(int x, int y, int* p_sum, int* p_diff);

int main(void)
{
	int sum = 0, diff = 0;

	get_sum_diff(100, 200, &sum, &diff);	//100, 200과 sum, diff의 주소를 함수에 전달.
	printf("원소들의 합=%d\n", sum);
	printf("원소들의 차=%d\n", diff);

	return 0;
}

void get_sum_diff(int x, int y, int* p_sum, int* p_diff)
{
	*p_sum = x + y;		//포인터 p_sum에 저장된 주소에 x+y 값을 저장.
	*p_diff = x - y;	//포인터 p_diff에 저장된 주소에 x-y 값을 저장.
}