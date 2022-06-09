#include "ui.h"

extern int score;
extern int bestScore;

// 게임 라인 잡기
void ingame_line(void)
{
	system("mode con cols=70 lines=35");
	system("cls");

	for (int i = 1; i <= 30; i++) {
		SetColor(WHITE);
		gotoxy(GAMELINE, i); printf("┃");
		//Sleep(10);
	}
	for (int i = 1; i <= GAMELINE; i++) {
		SetColor(WHITE);
		gotoxy(i, 30); printf("━");
		//Sleep(10);
	}
}

// 최고 점수
void best_score_print(void)
{
	gotoxy(INGAME_X, INGAME_Y);
	printf("BEST SCORE : %11d", bestScore);
}

// 현재 점수
void now_score_print(void)
{
	gotoxy(INGAME_X, INGAME_Y + 1);
	printf("NOW  SCORE : %11d", score);
}
