#include "console.h"

void splash_screen(void)
{
	system("mode con cols=60 lines=25");
	int x = 13,
		y = 13;

	gotoxy(x, y);     printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(x, y + 1); printf("┃           무한의 계단	      ┃");
	gotoxy(x, y + 2); printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	gotoxy(x, y + 3); printf("            ver.내리막");

	for (int i = 1; i <= 8; ++i) {
		if (i == i) {
			SetColor(BLACK);
			gotoxy(x, y + 4);
			printf("■■■■■■■■■■■■■■■■■■■■■");
		}
		Sleep(60);
		SetColor(RED);
		gotoxy(x, y + 4);
		printf("     > PRESS ANY KEY TO START <");
		Sleep(60);
	}
	while (getch() == NULL) {};
	SetColor(WHITE);
}