#pragma once
#include <mysql/mysql.h>
#include <stdio.h>

#define DB_USER "root"				// ���� �̸�
#define DB_PASS "root1234"			// ��й�ȣ
#define DB_HOST "127.0.0.1"			// DB���� �ּ�
#define DB_NAME "school"			// Datebase ��Ű�� �ּ�

#define CHOP(x) x[strlen(x) - 1] = NULL

MYSQL con;
MYSQL_RES* sql_result;
MYSQL_ROW sql_row;

char loginId[20];

void mysql_init_setting(void);
MYSQL* DBConnection(void);

int checkID(char *);
int checkName(char* name);

int registeAccount(char*, char*, char*);
int login(char*, char*);

void saveScore(int score);

MYSQL_RES* getRankBoard(void);
MYSQL_RES* myScoreQuery(void);

int getUserBestScore(void);

int charsToInt(char*);