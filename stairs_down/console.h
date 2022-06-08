#pragma once
#include <windows.h>

#define ESC 27
#define ENTER 13
#define SPACE 32

#define ARROW_UP 72
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_DOWN 80


typedef enum
{
	VISIBLE_CURSOR,
	UNVISIBLE_CURSOR
} CURSOR_TYPE;

typedef enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
} COLOR_LIST;

void gotoxy(int, int);
void SetColor(COLOR_LIST);
void setCursorType(CURSOR_TYPE);