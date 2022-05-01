#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		//�������� ���ϱ� ���� math ���̺귯�� ����.
float make_pg(float fl[]);
float make_pch(float fl[], float m);

int main(void) {
	float fl[10];		//�Է� ���� �Ǽ� �迭
	float pg, pch;		//pg: ���, pch: ǥ������

	for (int i = 0; i < 10; i++) {
		printf("�����͸� �Է��Ͻÿ�:");
		scanf("%f", &fl[i]);		//�� ���� �Ǽ� ������ �Է�.
	}

	pg = make_pg(fl);
	pch = make_pch(fl, pg);

	printf("��հ��� %f\nǥ���������� %f\n", pg, pch);	//��� ���.

	return 0;
}

float make_pg(float fl[]) {			//fl�� m�� ���ϴ� �Լ�.
	float m = 0;					//m: m*10
	for (int i = 0; i < 10; i++) {	//�迭 fl�� ���Ҹ� ��� ���Ѵ�.
		m += fl[i];
	}
	return m / 10;					//m*10�� 10���� ���� m�� ���Ѵ�.
}

float make_pch(float fl[], float m) {	//fl�� �� ���ϴ� �Լ�.
	float v = 0;						//v: v*10
	for (int i = 0; i < 10; i++) {		//v*10�� ���� ���Ѵ�.
		v += (fl[i] - m) * (fl[i] - m);
	}
	return sqrt(v / 10);				//v*10�� 10���� ������ �������� ���Ͽ� �� ���Ѵ�.
}