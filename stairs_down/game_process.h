#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "console.h"
#include "ui.h"

//#define ESC 27
//#define ENTER 13
//#define SPACE 32

int bestScore;
int score;
// int level;

#define STRAIGHT 97
#define REVERSE 108

char playerPlace[29];

void in_out_pp(int);
int calcul(int);
void stair_print(void);

void first_game_process(void);

int get_userInput(int*);

int game(void);

void eachStair_add(int*);