#include"all.h"

void GetStageData(int stage_data[MAP_HEIGHT][MAP_WIDTH], int map_data[MAP_HEIGHT][MAP_WIDTH])
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			map_data[i][j] = stage_data[i][j];
		}
	}

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_X, WINDOW_Y, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	player *pl = new player();
	map_1 *map = new map_1();
	gamescene *scene = new gamescene();
	stage_data *stage = new stage_data();

	int girl;
	int music;
	int clearCheck = false;
	girl = LoadGraph("PS_lady.png");
	music = LoadSoundMem("BGM.mp3");

	SetFontSize(128);
	int color = GetColor(0, 155, 250);

	GetStageData(stage->stage_1, map->map_data);
	GetStageData(map->map_data, pl->stg_data);

	//スタート画面設定
	SetFontSize(128);
	StartScene(scene->sceneCnt, scene->start_1, scene->start_2, girl, color);

	ChangeVolumeSoundMem(120, music);
	PlaySoundMem(music, DX_PLAYTYPE_LOOP, false);

	while (ProcessMessage() != -1)		//ゲームループ
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			delete pl;
			delete map;
			delete scene;
			delete stage;

			DxLib_End();

			return 0;
		}

		if (CheckHitKey(KEY_INPUT_R) == 1)
		{
			pl->ReStart();
			map->mapdrawpoint_x = 0;
		}

		if (CheckHitKey(KEY_INPUT_LCONTROL) && CheckHitKey(KEY_INPUT_S))
		{
			if (isCheckSaveExist)
			{

			}
		}

		switch (pl->plgoalFlg)
		{
		case false:
			pl->pldrawpoint_x = map->mapdrawpoint_x;
			pl->pldrawpoint_y = map->mapdrawpoint_y;

			if (pl->pos_x > WINDOW_X - PL_SIZE)
			{
				pl->pos_x = 1;
				map->mapdrawpoint_x += WINDOW_X / CHIP_SIZE;
			}
			if (pl->pos_x < 0)
			{
				if (map->mapdrawpoint_x == -1)
				{
					pl->ReStart();
				}
				pl->pos_x = WINDOW_X - PL_SIZE - 1;
				map->mapdrawpoint_x -= WINDOW_X / CHIP_SIZE;
			}

			map->View();
			pl->All();

			if (pl->plLiveFlg == false)
			{
				SetFontSize(128);
				pl->saveStrFlg = false;
				while (true)
				{
					if ((CheckHitKey(KEY_INPUT_RETURN) || (CheckHitKey(KEY_INPUT_LCONTROL) && CheckHitKey(KEY_INPUT_Z))))
					{
						pl->Retry();
						ClearDrawScreen();
						map->mapdrawpoint_x = pl->retryPoint_pldraw_x;
						pl->plLiveFlg = true;
						pl->saveFlg = true;
						break;
					}
					DrawString(150, 150, "Please CTRL + Z", color);
					//					DrawString(400, 300, "", color);
					DrawString(400, 450, "→ Retry", color);
					ScreenFlip();
				}
			}

			if (map->mapdrawpoint_x == 0 && pl->plgoalCnt == 0)
			{
				SetFontSize(90);
				DrawString(CHIP_SIZE * 21, CHIP_SIZE * 15, "↓", color);
			}
			if (pl->pldrawpoint_x == 1 && pl->plgoalCnt == 0)
			{
				DrawString(CHIP_SIZE * 13, CHIP_SIZE * 2, "↑", color);
			}
			if (pl->plgoalCnt == 1 && (pl->pldrawpoint_x / 40) == 1)
			{
				SetFontSize(90);
				DrawString(CHIP_SIZE * 2 + 3, CHIP_SIZE * 13, "↓", color);
			}

			ScreenFlip();
			ClearDrawScreen();

			continue;

		case true:
			if (pl->plgoalCnt > 1)
			{
				break;
			}
			ClearScene(scene->sceneCnt, scene->clear_1, scene->clear_2, color);
			pl->ReStart();
			map->mapdrawpoint_x = 0;
			scene->plClearCnt++;
			GetStageData(stage->stage_2, map->map_data);
			GetStageData(map->map_data, pl->stg_data);

			continue;
		}

		//ゲームクリア挿入
		ClearGame(scene->sceneCnt, color);
		pl->ReStart();
		map->mapdrawpoint_x = 0;
		clearCheck = true;
		break;
	}


	delete pl;
	delete map;
	delete scene;
	delete stage;

	DxLib_End();

	return 0;
}




