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

	printf("��A�� ��B�� x, y��ǥ�� ���� ������� �Է��Ͻÿ�.\n");
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	d = getDistance(x1, x2, y1, y2);

	printf("�� �� ������ �Ÿ��� %f�Դϴ�.", d);
	return 0;
}