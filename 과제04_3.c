#include <stdio.h>
#include <time.h>
int prt_bd();
int is_what(int i, int j);
int move();
int move_m();
int shp[2] = { 0, 0 }, m[2][2], g[2] = { 9, 9 }, plr;	//전역변수로 선언하여 매개변수를 통하지 않고도 변수 값를 읽거나 변경할 수 있게 함.
														//shp: 플레이어 위치(#), m: 몬스터(M), g: 금(G), plr: 플레이어의 이동방향
int main(void) {
	srand(time(NULL));					//게임을 새로 시작할 때마다 몬스터의 초기 위치가 달라지게 한다.
	for (int i = 0; i < 2; i++) {		//플레이어 근처나 금과 겹치지 않는 범위에서 몬스터 두 개를 랜덤으로 생성.
		m[i][0] = rand() % 7 + 1;
		m[i][1] = rand() % 9;
	}
	prt_bd();
	while (1) {
		move();								//플레이어 위치 이동.
		move_m();							//몬스터 위치 이동.
		system("cls");						//화면 초기화.
		prt_bd();							//게임판 출력.
		int k = is_what(shp[0], shp[1]);	//플레이어의 위치가 몬스터나 금과 겹치는지 확인.
		if (k == 1) {				//몬스터와 겹칠 경우 실패로 게임 종료.
			printf("실패입니다.");
			break;
		}
		if (k == 3) {				//금과 겹칠 경우 성공으로 게임 종료.
			printf("성공입니다!");
			break;
		}
	}
	return 0;
}

int prt_bd() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int k = is_what(i, j);
			switch (k) {					//#이 M이나 G와 겹칠 때, M>#>G 순서로 겹치게 한다.
			case 1: printf("M "); break;	//몬스터는 플레이어를 먹고, 플레이어는 금을 먹기 때문이다.
			case 2: printf("# "); break;
			case 3: printf("G "); break;
			default: printf(". "); break;	//나머지는 빈 공간으로 표시.
			}
		}
		printf("\n");
	} printf("\n");
	return 0;
}

int is_what(int i, int j) {			//(i, j) 위치가 몬스터면 1, 플레이어면 2, 금이면 3, 빈 공간이면 0을 반환하는 함수.
	if (i == m[0][0] && j == m[0][1] || i == m[1][0] && j == m[1][1]) return 1;
	else if (i == g[0] && j == g[1]) return 3;		//main함수에서 플레이어가 금을 먹었는지 확인하기 위해서는
	else if (i == shp[0] && j == shp[1]) return 2;	//플레이어의 위치보다 금의 위치를 우선적으로 판단해야 한다.
	return 0;
}

int move() {						//plr 값에 따라 플레이어 위치를 바꾸는 함수.
	plr = _getch();
	switch (plr) {
	case 'w': if (shp[0] == 0) break; shp[0] -= 1; break;	//옆으로 더 갈 수 없는 경우 현재 위치를 유지한다.
	case 's': if (shp[0] == 9) break; shp[0] += 1; break;
	case 'a': if (shp[1] == 0) break; shp[1] -= 1; break;
	case 'd': if (shp[1] == 9) break; shp[1] += 1; break;
	default: plr = _getch(); move(plr); break;				//wsad가 아닌 키를 눌렀을 경우 다시 입력받는다.
	} return 0;
}

int move_m() {						//몬스터 위치를 랜덤으로 바꾸는 함수.
	for (int i = 0; i < 2; i++) {	//플레이어가 몬스터 움직임을 어느정도 예상할 수 있도록
		int drt = rand() % 4;		//네 가지 방향 중 한 방향으로 1만큼 이동하도록 했다.
		switch (drt) {				//마찬가지로 금과 겹치지 않는 범위에서 움직인다.
		case 0: if (m[i][0] == 0) { m[i][0] += 1; break; } m[i][0] -= 1; break;
		case 1: if (m[i][0] == 8) { m[i][0] -= 1; break; } m[i][0] += 1; break;
		case 2: if (m[i][1] == 0) { m[i][1] += 1; break; } m[i][1] -= 1; break;
		case 3: if (m[i][1] == 8) { m[i][1] -= 1; break; } m[i][1] += 1; break;
		default: break;				//옆으로 더 갈 수 없는 경우 반대쪽으로 움직인다.
		}
	}
	return 0;
}