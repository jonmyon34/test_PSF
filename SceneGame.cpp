#include"all.h"


void StartScene(int sceneCnt, int start_1, int start_2, int girl, int color)		//スタート画面ループ
{
	while (1)
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			ClearDrawScreen();
			DrawString(40, 150, "　↑↓↓←→←→PS", color);
			ScreenFlip();

			if (isCommandCheck(color))
			{
				for (int i = 0; i < 300; i++)
				{
					DrawExtendGraph(0, 0, WINDOW_X, WINDOW_Y, girl, true);
					ScreenFlip();
				}
				ClearDrawScreen();
			}
		}

		switch ((sceneCnt / 60) % 2)
		{
		case 0:
			DrawString(40, 150, "↑↑↓↓←→←→PS", color);
			break;

		case 1:
			DrawString(40, 150, "↑↑↓↓←→←→PS", color);
			DrawString(230, 400, "Please ENTER", color);
			break;

		default:
			break;
		}

		ScreenFlip();
		ClearDrawScreen();

		sceneCnt++;

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			sceneCnt = 0;
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			exit(true);
		}
	}
}


void ClearScene(int sceneCnt, int clear_1, int clear_2,int color)		//ステージクリア画面ループ
{
	while (1)
	{
		switch ((sceneCnt / 60) % 2)
		{
		case 0:
			SetFontSize(164);
			DrawString(80, 150, "STAGE  CLEAR !", color);

			break;

		case 1:
			SetFontSize(164);
			DrawString(80, 150, "STAGE  CLEAR !", color);
			SetFontSize(128);
			DrawString(230, 450, "ENTER → NEXT", color);

			break;

		default:
			break;
		}

		ScreenFlip();
		ClearDrawScreen();

		sceneCnt++;

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			sceneCnt = 0;
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			exit(true);
		}
	}
}


void ClearGame(int sceneCnt, int color)		//ステージクリア画面ループ
{
	while (1)
	{
		switch ((sceneCnt / 60) % 2)
		{
		case 0:
			SetFontSize(164);
			DrawString(80, 150, " GAME CLEAR !", color);

			break;

		case 1:
			SetFontSize(164);
			DrawString(80, 150, " GAME CLEAR !", color);
			SetFontSize(32);
			DrawString(720, 500, "if(TITLE && COMMAND)...?", color);

			break;

		default:
			break;
		}

		ScreenFlip();
		ClearDrawScreen();

		sceneCnt++;

		if (CheckHitKey(KEY_INPUT_RETURN) == 1)
		{
			sceneCnt = 0;
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			exit(true);
		}
	}
}



int isCommandCheck(int color)
{
	WaitKey();
	if (!CheckHitKey(KEY_INPUT_UP))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　↓↓←→←→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_DOWN))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　↓←→←→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_DOWN))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　←→←→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　　→←→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　　　←→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　　　　→PS", color);
	ScreenFlip();

	WaitKey();
	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　　　　　PS", color);
	ScreenFlip();


	WaitKey();
	if (!CheckHitKey(KEY_INPUT_P))
	{
		return 0;
	}
	ClearDrawScreen();
	DrawString(40, 150, "　　　　　　　   S", color);
	ScreenFlip();


	WaitKey();
	if (!CheckHitKey(KEY_INPUT_S))
	{
		return 0;
	}

	return 1;
}
