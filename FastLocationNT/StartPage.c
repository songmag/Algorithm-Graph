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
			//graphprintchoose();�׷��� ��¼���
			break;
		case 3:
			application();
			break;
		case 4:
			return;
		default:
			printf("��Ȯ�� ���� �Է����ּ��� \n");
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