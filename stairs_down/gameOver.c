extern int score;

void gameOver(void)
{
	system("cls");
	system("mode con: cols=40 lines=13");
	gotoxy(15, 5);
	printf("점수 : %d\n", score);
	
	char ch;
	gotoxy(5, 7);
	printf("기록을 저장하시겠습니까? (Y/N)");
	Sleep(500);
	ch = _getch();

	if (ch == 'y' || ch == 'Y')
		saveScore(score);
}