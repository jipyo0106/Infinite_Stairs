#include "console.h"
#include "db_ui.h"
#include "ui.h"
#include "game_process.h"
#include <conio.h>

void howControl(void) {
	system("cls");
	system("mode con cols=70 lines=20");
	int x = 4, y = 7;

	SetColor(DARK_RED);
	gotoxy(x, y);
	printf("HOW CONTROLL ?");

	SetColor(GRAY);
	gotoxy(x + 5, y + 3); printf("Keep Going Key       : '%c'", 'A');
	gotoxy(x + 5, y + 5); printf("Change Direction Key : '%c'", 'L');

	SetColor(WHITE);

	_getch();
}

int menuScreen(void)
{
	system("cls");
	system("mode con cols=40 lines=10");

	int cursor = 0,
		select = 0;
	char *str[6]= {
		"1. 내 스코어", 
		"2. 전체 랭킹", 
		"3. 게임 시작", 
		"4. 조작 방법",
		"5. 로그 아웃",
		"6. 게임 종료"
	};

	do {
		for (int i = 0; i < 6; i++) {
			gotoxy(14, 3 + i);
			if (cursor == i) {
				SetColor(GREEN);
				
				printf("%s", str[i]);
				SetColor(WHITE);
			}
			else {
				printf("%s", str[i]);
			}
		}

		select = _getch();

		if (select == 224) {
			select = _getch();
			// UP
			if (select == ARROW_UP && cursor != 0)
				cursor--;
			// DOWN
			else if (select == ARROW_DOWN && cursor != 5)
				cursor++;
		}
		else if (select == SPACE || select == ENTER) {
			break;
		}
		system("cls");
	} while (1);

	return action(cursor);
}

int action(int cursor)
{
	int returnValue = 0;
	switch (cursor)
	{
	case 0:
		myScoreUI();
		returnValue = 0;
		break;
	case 1:
		RankingUI();
		returnValue = 1;
		break;
	case 2:
		game();
		returnValue = 2;
		break;
	case 3:
		howControl();
		returnValue = 3;
		break;
	case 4:
		login_registe_select_UI();
		returnValue = 4;
		break;
	case 5:
		returnValue = 5;
		break;
	}

	return returnValue;
}