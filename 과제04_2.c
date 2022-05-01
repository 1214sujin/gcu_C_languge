#include <stdio.h>
#include <time.h>

int main(void) {
	int i, j, rnd[10][10];
	srand(time(NULL));					//실행시마다 지뢰의 위치가 달라지게 한다.
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			rnd[i][j] = rand() % 99;	//배열 rnd[10][10]에 0~99의 수를 랜덤으로 저장하여
		}								//특정 수 이하의 값을 가지는 곳만 지뢰가 되도록 한다.
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			if (rnd[i][j] < 30) printf("# ");	//약 30개의 지뢰가 만들어진다.
			else printf(". ");					//나머지는 빈 공간으로 표시.
		printf("\n");							//10줄마다 줄바꿈 해서 10*10 정사각형을 만든다.
	}
	return 0;
}