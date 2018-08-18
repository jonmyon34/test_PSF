class gamescene
{
public:
	int start_1, start_2;
	int clear_1, clear_2;
	int gameover_1, gameover_2;
	int gameend_1, gameend_2;


	int sceneCnt;

	int plClearCnt;

	gamescene()
	{
		start_1 = LoadGraph("start1.png");
		start_2 = LoadGraph("start2.png");

		clear_1 = LoadGraph("clear_1.png");
		clear_2 = LoadGraph("clear_2.png");


		sceneCnt = 0;
		plClearCnt = 0;
	}
};

void StartScene(int, int, int,int,int);
void ClearScene(int, int, int, int);
void ClearGame(int, int);
int isCommandCheck(int);
