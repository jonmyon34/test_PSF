
class player
{
public:
	int x, y, pos_x, pos_y, width, height;
	float speed_x;
	int speed_y;
	int hp;
	float pl_jump_power;
	int pldrawpoint_x, pldrawpoint_y;
	int stg_data[MAP_HEIGHT][MAP_WIDTH];
	int player_gh;
	int plCnt_x, plCnt_y;
	int plUpCnt;

	int retryPoint_x, retryPoint_y;
	int retryPoint_pos_x, retryPoint_pos_y;
	int retryPoint_pldraw_x;

	int saveFlg;
	int saveStrFlg;
	int drawSaveCnt;
	int save_effect_gh, save_effect_gh_1;

	bool plgoalFlg;
	int plgoalCnt;
	bool plLiveFlg;

	int str_color;


	player()
	{
		x = 240;
		pos_x = 240;
		y = GROUND;
		pos_y = GROUND;
		speed_x = 7;
		speed_y = 20;
		width = 32;
		height = 32;
		hp = 30;
		player_gh = LoadGraph("Ps_pl.png");

		plCnt_x = 0;
		plCnt_y = 0;

		retryPoint_x = x;
		retryPoint_y = y;
		retryPoint_pos_x = pos_x;
		retryPoint_pos_y = pos_y;
		retryPoint_pldraw_x = 0;

		pl_jump_power = 0;

		plgoalFlg = false;

		saveFlg = false;
		saveStrFlg = false;
		drawSaveCnt = 0;
		save_effect_gh = LoadGraph("save_effect.png");


		plgoalCnt = 0;

		plLiveFlg = true;
		str_color = GetColor(0, 155, 250);
	}

	void ReStart()
	{
		x = 240;
		pos_x = 240;
		y = GROUND;
		pos_y = GROUND;
		speed_x = 0;
		speed_y = 20;
		width = 32;
		height = 32;
		hp = 30;
		player_gh = LoadGraph("Ps_pl.png");

		plCnt_x = 0;
		plCnt_y = 0;

		plUpCnt = 0;

		retryPoint_x = x;
		retryPoint_y = y;
		retryPoint_pos_x = pos_x;
		retryPoint_pos_y = pos_y;
		retryPoint_pldraw_x = 0;

		saveFlg = false;
		drawSaveCnt = 0;

		pl_jump_power = 0;

		plgoalFlg = false;
		plLiveFlg = true;
	}

	void Retry()
	{
		x = retryPoint_x;
		y = retryPoint_y;
		pos_x = retryPoint_pos_x;
		pos_y = retryPoint_pos_y;
		pldrawpoint_x = retryPoint_pldraw_x;
		pl_jump_power = 0;
	}

	void Move()
	{

		if (speed_x > PL_MAX_SPEED)
		{
			speed_x = PL_MAX_SPEED_X;
		}
		if (pl_jump_power < -PL_MAX_SPEED)
		{
			pl_jump_power = -PL_MAX_SPEED;
		}

		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			if (speed_x < PL_MAX_SPEED_X)
			{
				speed_x = speed_x + 0.7;
			}

			if (isHitCheckRight(pos_x + speed_x, pos_y, stg_data, pldrawpoint_x) || isHitCheckRight(pos_x + speed_x, pos_y + PL_SIZE - 1, stg_data, pldrawpoint_x))
			{
				pos_x = ((pos_x / CHIP_SIZE) + 1)*CHIP_SIZE - 1;
			}
			else
			{
				pos_x += speed_x;
				x += speed_x;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			if (speed_x < PL_MAX_SPEED_X)
			{
				speed_x = speed_x + 0.7;
			}
			if (isHitCheckLeft(pos_x - speed_x, pos_y, stg_data, pldrawpoint_x) || isHitCheckLeft(pos_x - speed_x, pos_y + PL_SIZE - 1, stg_data, pldrawpoint_x))
			{
				pos_x = ((pos_x / CHIP_SIZE))*CHIP_SIZE + 1;
			}
			else
			{
				pos_x -= speed_x;
				x -= speed_x;
			}
		}

		if (!CheckHitKey(KEY_INPUT_RIGHT) && !CheckHitKey(KEY_INPUT_LEFT))
		{
			speed_x = 0;
		}

		plCnt_x = x / WINDOW_X;
		x = pos_x + plCnt_x * WINDOW_X;

		if (isHitCheckDown(pos_x + PL_SIZE, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x) || isHitCheckDown(pos_x, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x))
		{
			pl_jump_power = 0;

			if (CheckHitKey(KEY_INPUT_UP) && isHitCheckDown(pos_x + PL_SIZE, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x) || CheckHitKey(KEY_INPUT_UP) && isHitCheckDown(pos_x, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x))
			{
				pl_jump_power = 15;

				if (isHitCheckUp(pos_x + PL_SIZE, pos_y - pl_jump_power, stg_data, pldrawpoint_x) || isHitCheckUp(pos_x, pos_y - pl_jump_power, stg_data, pldrawpoint_x))
				{
					pos_y = (pos_y / CHIP_SIZE)*CHIP_SIZE + PL_SIZE + 1;
					pl_jump_power = 0;
				}
				else
				{
					pos_y -= pl_jump_power;
				}
			}
		}
		else
		{
			pl_jump_power -= 0.7;
			pos_y -= pl_jump_power;

			if (isHitCheckUp(pos_x + PL_SIZE, pos_y, stg_data, pldrawpoint_x) || isHitCheckUp(pos_x, pos_y, stg_data, pldrawpoint_x))
			{
				pos_y = (pos_y / CHIP_SIZE)*CHIP_SIZE + PL_SIZE + 1;
				pl_jump_power = 0;
			}
			if (isHitCheckDown(pos_x + PL_SIZE, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x) || isHitCheckDown(pos_x, pos_y + PL_SIZE - pl_jump_power, stg_data, pldrawpoint_x))
			{
				pos_y = (pos_y / CHIP_SIZE)*CHIP_SIZE + PL_SIZE;
			}
		}

		if (pos_y + PL_SIZE < 0)
		{
			pos_y = WINDOW_Y;
		}
		if ((pos_y + PL_SIZE > WINDOW_Y&&isHitCheckDown(pos_x, 0, stg_data, pldrawpoint_x)) || (pos_y + PL_SIZE > WINDOW_Y&&isHitCheckDown(pos_x + PL_SIZE, 0, stg_data, pldrawpoint_x)))
		{
			pos_y = WINDOW_Y - PL_SIZE;
			pl_jump_power = 0;
			if (CheckHitKey(KEY_INPUT_UP))
			{
				pl_jump_power = 15;
				if (isHitCheckUp(pos_x + PL_SIZE, pos_y - pl_jump_power, stg_data, pldrawpoint_x) || isHitCheckUp(pos_x, pos_y - pl_jump_power, stg_data, pldrawpoint_x))
				{
					pos_y = (pos_y / CHIP_SIZE)*CHIP_SIZE + PL_SIZE + 1;
					pl_jump_power = 0;
				}
				else
				{
					pos_y -= pl_jump_power;
				}
			}
		}
		if (pos_y > WINDOW_Y)
		{
			pos_y = 0;
		}

		plCnt_y = y / WINDOW_Y;
		y = pos_y + plCnt_y * WINDOW_Y;

		if (isHitCheckCenter(pos_x + (PL_SIZE / 2), pos_y + (PL_SIZE / 2), stg_data, pldrawpoint_x))
		{
			pos_y = pos_y - CHIP_SIZE;
		}

		if (saveFlg == false)
		{
			if (isSavePointCheck(pos_x + (PL_SIZE / 2), pos_y + (PL_SIZE / 2), stg_data, pldrawpoint_x))
			{
				PlaySoundFile("save.mp3", DX_PLAYTYPE_BACK);
				retryPoint_x = x;
				retryPoint_y = y;
				retryPoint_pos_x = pos_x;
				retryPoint_pos_y = pos_y;
				retryPoint_pldraw_x = pldrawpoint_x;
				saveFlg = true;
				saveStrFlg = true;
			}
		}
		else
		{
			if (drawSaveCnt < 120)
			{
				switch ((drawSaveCnt / 15) % 2)
				{
				case 0:
					SetFontSize(40);

					if (saveStrFlg)
					{
						DrawString(150, 150, "•Û‘¶‚µ‚Ü‚µ‚½", str_color);
						DrawRectGraph(retryPoint_pos_x - 16, retryPoint_pos_y - 16, 0, 0, CHIP_SIZE * 2, CHIP_SIZE * 2, save_effect_gh, true, false);
					}
					drawSaveCnt++;
					break;
				case 1:
					SetFontSize(40);
					if (saveStrFlg)
					{
						DrawString(150, 150, "•Û‘¶‚µ‚Ü‚µ‚½", str_color);
						DrawRectGraph(retryPoint_pos_x - 16, retryPoint_pos_y - 16, 64, 0, CHIP_SIZE * 2, CHIP_SIZE * 2, save_effect_gh, true, false);
					}
					drawSaveCnt++;
					break;
				}
			}
			else
			{
				saveFlg = false;
				drawSaveCnt = 0;
			}
		}

		if (isDamageCheck(pos_x + (PL_SIZE / 2), pos_y + (PL_SIZE / 2), stg_data, pldrawpoint_x))
		{
			PlaySoundFile("damage.mp3", DX_PLAYTYPE_BACK);
			plLiveFlg = false;
		}

		if (isGoalCheck(pos_x, pos_y, stg_data, pldrawpoint_x))
		{
			plgoalFlg = true;
			plgoalCnt++;
		}


	}

	void View()
	{
		DrawExtendGraph(pos_x, pos_y, pos_x + width, pos_y + height, player_gh, true);
	}

	void All()
	{
		Move();
		View();
	}
};


