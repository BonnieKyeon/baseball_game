#define MAX_BALL_NUM 10
#define BALL_ARR_LENGTH 3
#define MAX_CHANCE_COUNT 10
#define ERROR -1
#define SUCCESS 0

/* ������ �� ������ �غ�. �� ���ڸ� �ٽ� ����. */
void setupNewGame();

/*	���ڿ� �ڸ��� �̸� set ���� mBallNumArr �� ���Ѵ�.
	return ���� ERROR �� ������ ����. */
int umpireNumBallArr(int ballNumArr[BALL_ARR_LENGTH], int *strikeCount, int *ballCount);
