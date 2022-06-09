#include "db_ui.h"
#include "console.h"
#include <conio.h>

// �α��� || ȸ������ ���� UI
void login_registe_select_UI(void)
{
	int cursor = 0,
		select = 0;
	char* str[5] = {" �α���", "ȸ������"};

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

// �α��� UI
int loginUI(void)
{
	char id[20] = { 0 },
		pass[20] = { 0 };

	int gotoX = 11,
		gotoY = 7;

	system("cls");
	system("mode con: cols=40 lines=15");

	gotoxy(gotoX, gotoY);
	printf("���̵�   : ");
	fgets(id, 20, stdin);	CHOP(id);

	gotoxy(gotoX, gotoY + 1);
	printf("��й�ȣ : "); 
	fgets(pass, 20, stdin);	CHOP(pass);

	int loginCheck = 0;
	gotoxy(gotoX + 3, gotoY + 4);
	(loginCheck = login(id, pass) == 1) ? printf("�α��� ����\n"): printf("�α��� ����\n");

	_getch();
	return (loginCheck == 1) ? 3 : 0;
}

// ȸ������ UI
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
	printf("���̵�   : ");
	fgets(id, 20, stdin);	CHOP(id);

	gotoxy(gotoX, gotoY + 1);
	printf("��й�ȣ : ");
	fgets(pass, 20, stdin);	CHOP(pass);

	gotoxy(gotoX, gotoY + 2);
	printf("�г���   : ");
	fgets(name, 10, stdin);	CHOP(name);

	gotoxy(gotoX + 3, gotoY + 4);
	if (checkID(id) != 0) {
		printf("���̵� �ߺ�");
		_getch();
		return;
	}
	else if (checkName(name) != 0) {
		printf("�г��� �ߺ�");
		_getch();
		return;
	}
	
	(registeAccount(id, pass, name) == 1) ? printf("ȸ�� ���� ����\n") : printf("ȸ�� ���� ����\n");
	_getch();
}

// ��ü ��ŷ UI
void RankingUI(void)
{
	system("cls");
	system("mode con: cols=40 lines=15");

	MYSQL_RES* ranking = getRankBoard();

	printf("��������������������������������������������������������������������\n");
	printf("��                    ��           ��\n");
	printf("��������������������������������������������������������������������\n");
	for (int i = 0; i < 10; i++) {
		printf("��                    ��           ��\n");
	}
	printf("��������������������������������������������������������������������\n");


	gotoxy(9, 2);
	printf("�г���");
	gotoxy(26, 2);
	printf("���ھ�");

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

// �� ���ھ� ��� UI
void myScoreUI(void)
{
	system("cls");
	system("mode con: cols=20 lines=15");

	MYSQL_RES* scores = myScoreQuery();

	printf("��������������������������\n");
	printf("��           ��\n");
	printf("��������������������������\n");
	for (int i = 0; i < 10; i++) {
		printf("��           ��\n");
	}
	printf("��������������������������\n");

	gotoxy(5, 2);
	printf("���ھ�");

	int i = 0;

	while ((sql_row = mysql_fetch_row(scores)) != NULL) {
		gotoxy(2, 4 + i);
		printf("%11s", sql_row[0]);
		i++;
	}

	mysql_free_result(scores);

	_getch();
}