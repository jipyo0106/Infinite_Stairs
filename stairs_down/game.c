#include "game_process.h"

extern int getUserBestScore(void);
extern void gotoxy(int, int);

int game(void)
{
	first_game_process();

	int stair_ = -2;

	do {
		if (get_userInput(&stair_) == 1)
			break;

		eachStair_add(&stair_);

		in_out_pp(playerPlace[28] + calcul(28));
		score++;

		// UI
		stair_print();
		now_score_print();
		gotoxy(22, 1);
		SetColor(GREEN);
		stair_ == -2 ? printf("→") : printf("←");
		SetColor(WHITE);

	} while (1);
	gameOver();
}

int get_userInput(int *stair_)
{
	int user = _getch();

	if (user == REVERSE)
		*stair_ = (*stair_) * -1;
	else if (user != STRAIGHT)
		*stair_ = 0;

	return (playerPlace[1] == 0) ? 0 : 1;
}

void in_out_pp(int new_)
{
	for (int i = 0; i < 28; i++)
		playerPlace[i] = playerPlace[i + 1];

	playerPlace[28] = new_;
}

void eachStair_add(int *stair_) 
{
	for (int i = 1; i < 29; i++)
		playerPlace[i] += *stair_;
}

// 계단 출력 function
void stair_print(void)
{
	gotoxy(1, 2);
	for (int i = 1; i < 29; i++) {
		if (playerPlace[i] >= 20 || playerPlace[i] <= -21) {
			for (int j = -21; j < 19; j++) {
				printf(" ");
			}
			printf("\n");
			continue;
		}

		for (int j = -21; j < playerPlace[i]; j++) {
			printf(" ");
		}
		printf("─");
		for (int j = playerPlace[i]; j < 18; j++) {
			printf(" ");
		}
		printf("\n");
	}
}

// 계단 방향 계산 function
int calcul(int b_idx)
{
	return 
		(rand() % 3 == 0)
		? playerPlace[b_idx - 1] - playerPlace[b_idx] 
		: playerPlace[b_idx] - playerPlace[b_idx - 1];
}

// 게임 시작 시 초기 계단 위치 설정 function
void first_game_process(void)
{
	// 랜덤 seed값 설정
	srand(time(NULL));

	bestScore = getUserBestScore();
	score = 0;

	// 게임 UI 잡기
	ingame_line();
	best_score_print();
	
	now_score_print();

	// 계단 초기 생성 1
	playerPlace[0] = 0;
	playerPlace[1] = 0;
	playerPlace[2] = 2;
	playerPlace[3] = 4;
	playerPlace[4] = 6;


	// 계단 초기 생성 2
	for (int i = 5; i < 29; i++)
		playerPlace[i] = playerPlace[i - 1] + calcul(i - 1);

	// 계단 진행 방향 출력
	gotoxy(22, 1);
	SetColor(GREEN);
	printf("→");
	SetColor(WHITE);

	// 계단 출력
	stair_print();
}