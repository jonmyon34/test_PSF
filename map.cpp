#include"all.h"


int isHitCheckDown(int pos_x, int pos_y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(pos_y / CHIP_SIZE)][(pos_x / CHIP_SIZE) + mapdrawpoint_x] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isHitCheckRight(int pos_x, int pos_y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(pos_y / CHIP_SIZE)][(pos_x / CHIP_SIZE) + mapdrawpoint_x + 1] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isHitCheckLeft(int pos_x, int pos_y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(pos_y / CHIP_SIZE)][(pos_x / CHIP_SIZE) + mapdrawpoint_x] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isHitCheckUp(int pos_x, int pos_y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(pos_y / CHIP_SIZE)][(pos_x / CHIP_SIZE) + mapdrawpoint_x] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isHitCheckCenter(int pos_x, int pos_y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(pos_y / CHIP_SIZE)][(pos_x / CHIP_SIZE) + mapdrawpoint_x] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int isSavePointCheck(int x, int y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(y / CHIP_SIZE)][(x / CHIP_SIZE) + mapdrawpoint_x] == 7)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isDamageCheck(int x, int y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(y / CHIP_SIZE)][(x / CHIP_SIZE) + mapdrawpoint_x] == 8)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isGoalCheck(int x, int y, int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	if (map_data[(y / CHIP_SIZE)][(x / CHIP_SIZE) + mapdrawpoint_x] == 9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isCheckSaveExist(int map_data[MAP_HEIGHT][MAP_WIDTH], int mapdrawpoint_x)
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (map_data[i][j] == 7)
			{
				return 1;
			}
		}
	}
}