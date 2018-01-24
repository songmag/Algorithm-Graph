#include "FtLNT.h"

void main()
{
	COORD xy;
	Divice command;
	Graphinit();
	xy.X = 0;
	xy.Y = 0;
	while (1)
	{
		mainPage();
		command = NULL;
		switch (chooseDivice[0])
		{
		case 1:
			graphinitprint();
			break;
		case 2:
			graphprintchoose();
			//graphprintchoose();그래프 출력선택
			break;
		case 3:
			application();
			break;
		case 4:
			return;
		default:
			printf("정확한 값을 입력해주세요 \n");
			break;
		}
		if (command == NULL)
		{
			continue;
		}
		system("cls");
		command();
		system("cls");
	}
}