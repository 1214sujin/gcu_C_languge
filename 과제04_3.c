#include <stdio.h>
#include <time.h>
int prt_bd();
int is_what(int i, int j);
int move();
int move_m();
int shp[2] = { 0, 0 }, m[2][2], g[2] = { 9, 9 }, plr;	//���������� �����Ͽ� �Ű������� ������ �ʰ� ���� ���� �аų� ������ �� �ְ� ��.
														//shp: �÷��̾� ��ġ(#), m: ����(M), g: ��(G), plr: �÷��̾��� �̵�����
int main(void) {
	srand(time(NULL));					//������ ���� ������ ������ ������ �ʱ� ��ġ�� �޶����� �Ѵ�.
	for (int i = 0; i < 2; i++) {		//�÷��̾� ��ó�� �ݰ� ��ġ�� �ʴ� �������� ���� �� ���� �������� ����.
		m[i][0] = rand() % 7 + 1;
		m[i][1] = rand() % 9;
	}
	prt_bd();
	while (1) {
		move();								//�÷��̾� ��ġ �̵�.
		move_m();							//���� ��ġ �̵�.
		system("cls");						//ȭ�� �ʱ�ȭ.
		prt_bd();							//������ ���.
		int k = is_what(shp[0], shp[1]);	//�÷��̾��� ��ġ�� ���ͳ� �ݰ� ��ġ���� Ȯ��.
		if (k == 1) {				//���Ϳ� ��ĥ ��� ���з� ���� ����.
			printf("�����Դϴ�.");
			break;
		}
		if (k == 3) {				//�ݰ� ��ĥ ��� �������� ���� ����.
			printf("�����Դϴ�!");
			break;
		}
	}
	return 0;
}

int prt_bd() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int k = is_what(i, j);
			switch (k) {					//#�� M�̳� G�� ��ĥ ��, M>#>G ������ ��ġ�� �Ѵ�.
			case 1: printf("M "); break;	//���ʹ� �÷��̾ �԰�, �÷��̾�� ���� �Ա� �����̴�.
			case 2: printf("# "); break;
			case 3: printf("G "); break;
			default: printf(". "); break;	//�������� �� �������� ǥ��.
			}
		}
		printf("\n");
	} printf("\n");
	return 0;
}

int is_what(int i, int j) {			//(i, j) ��ġ�� ���͸� 1, �÷��̾�� 2, ���̸� 3, �� �����̸� 0�� ��ȯ�ϴ� �Լ�.
	if (i == m[0][0] && j == m[0][1] || i == m[1][0] && j == m[1][1]) return 1;
	else if (i == g[0] && j == g[1]) return 3;		//main�Լ����� �÷��̾ ���� �Ծ����� Ȯ���ϱ� ���ؼ���
	else if (i == shp[0] && j == shp[1]) return 2;	//�÷��̾��� ��ġ���� ���� ��ġ�� �켱������ �Ǵ��ؾ� �Ѵ�.
	return 0;
}

int move() {						//plr ���� ���� �÷��̾� ��ġ�� �ٲٴ� �Լ�.
	plr = _getch();
	switch (plr) {
	case 'w': if (shp[0] == 0) break; shp[0] -= 1; break;	//������ �� �� �� ���� ��� ���� ��ġ�� �����Ѵ�.
	case 's': if (shp[0] == 9) break; shp[0] += 1; break;
	case 'a': if (shp[1] == 0) break; shp[1] -= 1; break;
	case 'd': if (shp[1] == 9) break; shp[1] += 1; break;
	default: plr = _getch(); move(plr); break;				//wsad�� �ƴ� Ű�� ������ ��� �ٽ� �Է¹޴´�.
	} return 0;
}

int move_m() {						//���� ��ġ�� �������� �ٲٴ� �Լ�.
	for (int i = 0; i < 2; i++) {	//�÷��̾ ���� �������� ������� ������ �� �ֵ���
		int drt = rand() % 4;		//�� ���� ���� �� �� �������� 1��ŭ �̵��ϵ��� �ߴ�.
		switch (drt) {				//���������� �ݰ� ��ġ�� �ʴ� �������� �����δ�.
		case 0: if (m[i][0] == 0) { m[i][0] += 1; break; } m[i][0] -= 1; break;
		case 1: if (m[i][0] == 8) { m[i][0] -= 1; break; } m[i][0] += 1; break;
		case 2: if (m[i][1] == 0) { m[i][1] += 1; break; } m[i][1] -= 1; break;
		case 3: if (m[i][1] == 8) { m[i][1] -= 1; break; } m[i][1] += 1; break;
		default: break;				//������ �� �� �� ���� ��� �ݴ������� �����δ�.
		}
	}
	return 0;
}