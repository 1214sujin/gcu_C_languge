#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Permutation(int n, int r);

int Permutation(int n, int r) {
	int i, p=1;
	for (i = 0; i < r; i++) {
		p *= n - i;
	}
	return p;
}

int main(void) {
	int n, r, p;
	
	printf("������ n�� r�� ������� �Է��Ͻÿ�.\n");
	scanf("%d %d", &n, &r);
	p = Permutation(n, r);
	
	printf("%dP%d = %d", n, r, p);
	return 0;
}