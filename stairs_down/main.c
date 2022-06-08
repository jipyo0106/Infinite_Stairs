#include "console.h"
#include "game_process.h"
#include "ui.h"
#include "db.h"

int main(void)
{
	setCursorType(UNVISIBLE_CURSOR);

	mysql_init(&con);
	mysql_options(&con, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(&con, MYSQL_INIT_COMMAND, "SET NAMES euckr");

	splash_screen();

	login_registe_select_UI();
	
	while (menuScreen() != 5) {}

	system("cls");
	return 0;
}