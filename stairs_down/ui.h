#pragma once

#include <stdio.h>
#include <Windows.h>
#include "console.h"

#define INGAME_X 43
#define INGAME_Y 3
#define GAMELINE 41

void ingame_line(void);
void best_score_print(void);
void now_score_print(void);

void splash_screen(void);

int menuScreen(void);
int action(int);

void howControl(void);

void gameOver(void);