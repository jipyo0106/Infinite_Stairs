extern int score;

void gameOver(void)
{
	system("cls");
	system("mode con: cols=40 lines=13");
	gotoxy(15, 5);
	printf("���� : %d\n", score);
	
	char ch;
	gotoxy(5, 7);
	printf("����� �����Ͻðڽ��ϱ�? (Y/N)");
	Sleep(500);
	ch = _getch();

	if (ch == 'y' || ch == 'Y')
		saveScore(score);
}