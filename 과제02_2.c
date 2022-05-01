#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
float getDistance(int x1, int x2, int y1, int y2);

float getDistance(int x1, int x2, int y1, int y2) {
	float d;
	d = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	return d;
}

int main(void) {
	float x1, x2, y1, y2, d;

	printf("점A와 점B의 x, y좌표를 각각 순서대로 입력하시오.\n");
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	d = getDistance(x1, x2, y1, y2);

	printf("두 점 사이의 거리는 %f입니다.", d);
	return 0;
}