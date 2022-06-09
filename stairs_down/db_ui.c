#include "db_ui.h"
#include "console.h"
#include <conio.h>

// 로그인 || 회원가입 선택 UI
void login_registe_select_UI(void)
{
	int cursor = 0,
		select = 0;
	char* str[5] = {" 로그인", "회원가입"};

	for (int i = 0; i < 20; i++)
		loginId[i] = NULL;
	
	do
	{
		system("cls");
		system("mode con: cols=25 lines=13");
		do
		{
			for (int i = 0; i < 2; i++) {
				gotoxy(10, 5 + i);
				if (cursor == i) {
					SetColor(GREEN);
					printf(str[i]);
					SetColor(WHITE);
				}
				else {
					printf(str[i]);
				}
			}

			select = _getch();
			if (select == 224) {
				system("cls");
				select = _getch();
				if (select == ARROW_UP && cursor != 0)
					cursor--;
				else if (select == ARROW_DOWN && cursor != 1)
					cursor++;
			}
			else if (select == ENTER) {
				break;
			}
			else if (select == ESC){
				system("cls");
				exit(0);
			}

		} while (1);

		if (cursor == 0)
			cursor = loginUI();
		else if (cursor == 1)
			registeUI();

	} while (cursor != 3);
}

// 로그인 UI
int loginUI(void)
{
	char id[20] = { 0 },
		pass[20] = { 0 };

	int gotoX = 11,
		gotoY = 7;

	system("cls");
	system("mode con: cols=40 lines=15");

	gotoxy(gotoX, gotoY);
	printf("아이디   : ");
	fgets(id, 20, stdin);	CHOP(id);

	gotoxy(gotoX, gotoY + 1);
	printf("비밀번호 : "); 
	fgets(pass, 20, stdin);	CHOP(pass);

	int loginCheck = 0;
	gotoxy(gotoX + 3, gotoY + 4);
	(loginCheck = login(id, pass) == 1) ? printf("로그인 성공\n"): printf("로그인 실패\n");

	_getch();
	return (loginCheck == 1) ? 3 : 0;
}

// 회원가입 UI
void registeUI(void)
{
	char id[20] = { 0 },
		pass[20] = { 0 },
		name[10] = { 0 };
	int gotoX = 11,
		gotoY = 7;

	system("cls");
	system("mode con: cols=40 lines=15");

	gotoxy(gotoX, gotoY);
	printf("아이디   : ");
	fgets(id, 20, stdin);	CHOP(id);

	gotoxy(gotoX, gotoY + 1);
	printf("비밀번호 : ");
	fgets(pass, 20, stdin);	CHOP(pass);

	gotoxy(gotoX, gotoY + 2);
	printf("닉네임   : ");
	fgets(name, 10, stdin);	CHOP(name);

	gotoxy(gotoX + 3, gotoY + 4);
	if (checkID(id) != 0) {
		printf("아이디 중복");
		_getch();
		return;
	}
	else if (checkName(name) != 0) {
		printf("닉네임 중복");
		_getch();
		return;
	}
	
	(registeAccount(id, pass, name) == 1) ? printf("회원 가입 성공\n") : printf("회원 가입 실패\n");
	_getch();
}

// 전체 랭킹 UI
void RankingUI(void)
{
	system("cls");
	system("mode con: cols=40 lines=15");

	MYSQL_RES* ranking = getRankBoard();

	printf("┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━┓\n");
	printf("┃                    ┃           ┃\n");
	printf("┠━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━┫\n");
	for (int i = 0; i < 10; i++) {
		printf("┃                    ┃           ┃\n");
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━┛\n");


	gotoxy(9, 2);
	printf("닉네임");
	gotoxy(26, 2);
	printf("스코어");

	int i = 0;

	while ((sql_row = mysql_fetch_row(ranking)) != NULL) {
		gotoxy(2, 4 + i);
		printf("%20s", sql_row[0]);
		gotoxy(23, 4 + i);
		printf("%11s", sql_row[1]);
		i++;
	}
	mysql_free_result(ranking);

	_getch();
}

// 내 스코어 기록 UI
void myScoreUI(void)
{
	system("cls");
	system("mode con: cols=20 lines=15");

	MYSQL_RES* scores = myScoreQuery();

	printf("┏━━━━━━━━━━━┓\n");
	printf("┃           ┃\n");
	printf("┠━━━━━━━━━━━┫\n");
	for (int i = 0; i < 10; i++) {
		printf("┃           ┃\n");
	}
	printf("┗━━━━━━━━━━━┛\n");

	gotoxy(5, 2);
	printf("스코어");

	int i = 0;

	while ((sql_row = mysql_fetch_row(scores)) != NULL) {
		gotoxy(2, 4 + i);
		printf("%11s", sql_row[0]);
		i++;
	}

	mysql_free_result(scores);

	_getch();
}