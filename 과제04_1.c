#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>		//제곱근을 구하기 위해 math 라이브러리 포함.
float make_pg(float fl[]);
float make_pch(float fl[], float m);

int main(void) {
	float fl[10];		//입력 받을 실수 배열
	float pg, pch;		//pg: 평균, pch: 표준편차

	for (int i = 0; i < 10; i++) {
		printf("데이터를 입력하시오:");
		scanf("%f", &fl[i]);		//열 개의 실수 데이터 입력.
	}

	pg = make_pg(fl);
	pch = make_pch(fl, pg);

	printf("평균값은 %f\n표준편차값은 %f\n", pg, pch);	//결과 출력.

	return 0;
}

float make_pg(float fl[]) {			//fl의 m을 구하는 함수.
	float m = 0;					//m: m*10
	for (int i = 0; i < 10; i++) {	//배열 fl의 원소를 모두 더한다.
		m += fl[i];
	}
	return m / 10;					//m*10을 10으로 나눠 m을 구한다.
}

float make_pch(float fl[], float m) {	//fl의 σ를 구하는 함수.
	float v = 0;						//v: v*10
	for (int i = 0; i < 10; i++) {		//v*10의 값을 구한다.
		v += (fl[i] - m) * (fl[i] - m);
	}
	return sqrt(v / 10);				//v*10을 10으로 나누고 제곱근을 구하여 σ를 구한다.
}