#include "db.h"

// mariadb connect
MYSQL* DBConnection(void)
{
	mysql_init(&con);
	mysql_options(&con, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(&con, MYSQL_INIT_COMMAND, "SET NAMES euckr");

	return mysql_real_connect(&con, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
}

// ���̵� �ߺ� üũ
// ��ȯ���� ī��Ʈ������ �־ 0�� �ƴϸ� �ߺ����� �ִٰ� �ϴ� ��
int checkID(char * id)
{
	MYSQL* connection = DBConnection();

	char query[100];
	sprintf(query, "SELECT id FROM userinfo WHERE id = '%s'", id);
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);

	int id_count = mysql_num_rows(sql_result);

	mysql_free_result(sql_result);
	mysql_close(connection);

	return id_count;
}
// �г��� �ߺ� üũ
int checkName(char* name)
{
	MYSQL* connection = DBConnection();

	char query[100];
	sprintf(query, "SELECT id FROM userinfo WHERE nickName = '%s'", name);
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);

	int name_count = mysql_num_rows(sql_result);

	mysql_free_result(sql_result);
	mysql_close(connection);

	return name_count;
}

// ȸ������
int registeAccount(char* id, char* pass, char* name)
{
	MYSQL* connection = DBConnection();

	char query[150];
	int result = 1;
	sprintf(query, "INSERT INTO userInfo VALUES ('%s', '%s', '%s')", id, pass, name);


	if (mysql_query(connection, query) != 0) {
		printf("MariaDB query Error : %s\n", mysql_error(&con));
		result = 0;
	}
	mysql_commit(connection);
	mysql_close(connection);

	return result;
}

// �α���
int login(char *id, char * pass)
{
	MYSQL* connection = DBConnection();

	char query[100];
	sprintf(query, "SELECT id FROM userinfo WHERE id = '%s' AND pass = '%s'", id, pass);
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);
	
	int row_count = mysql_num_rows(sql_result);
	if (row_count == 1) {
		sql_row = mysql_fetch_row(sql_result);
		strcpy(loginId, sql_row[0]);
	}

	mysql_free_result(sql_result);
	mysql_close(connection);

	return (row_count == 1) ? 1 : 0;
}

// ���ھ� ����
void saveScore(int score)
{
	MYSQL* connection = DBConnection();

	char query[100];
	sprintf(query, "INSERT INTO userScore VALUES ('%s', %d, DEFAULT)", loginId, score);
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	mysql_close(connection);
}

// ��ü ��ũ
MYSQL_RES* getRankBoard(void)
{
	MYSQL* connection = DBConnection();

	char query[200];
	sprintf(query, "SELECT i.nickName, s.score FROM userScore s, userInfo i where s.userInfo_id = i.id ORDER BY s.score DESC LIMIT 10");
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);

	mysql_close(connection);

	return sql_result;
}

// USER ���ھ� ���
MYSQL_RES* myScoreQuery(void)
{
	MYSQL* connection = DBConnection();

	char query[150];
	sprintf(query, "SELECT s.score FROM userScore s where userInfo_id = '%s' ORDER BY s.score DESC LIMIT 10", loginId);

	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);
	mysql_close(connection);

	return sql_result;
}

// USER �ְ� ���
int getUserBestScore(void)
{
	MYSQL* connection = DBConnection();

	char query[150];
	sprintf(query, "SELECT score FROM userScore s WHERE userInfo_id = '%s' ORDER BY score DESC LIMIT 1", loginId);
	if (mysql_query(connection, query) != 0)
		printf("MariaDB query Error : %s\n", mysql_error(&con));

	sql_result = mysql_store_result(connection);
	sql_row = mysql_fetch_row(sql_result);

	int bestScore_ = charsToInt(sql_row[0]);
	Sleep(2000);
	mysql_close(connection);
	return bestScore_;
}

// ���ڿ� -> ������
/*
	mysql_fetch_row������ ���� INT�̾ ���ڿ��� ���� ����
	�׷��� ���ڿ��� ���������� ��ȯ���ִ� �Լ�
*/
int charsToInt(char * intStr)
{
	int tempScore = 0,
		len = strlen(intStr);

	for (int i = 0; i < len; i++) {
		int digit = 1;
		for (int j = 0; j < (len - i - 1); j++) {
			digit *= 10;
		}
		tempScore += (intStr[i] - '0') * digit;
	}

	return tempScore;
}