#define MAX_BALL_NUM 10
#define BALL_ARR_LENGTH 3
#define CHANCE 10
#define ERROR -1
#define SUCCESS 0

/* 심판이 새 게임을 준비. 볼 숫자를 다시 세팅. */
void setupNewGame();

/*	숫자와 자리를 미리 set 해준 mBallNumArr 와 비교한다.
	return 값이 ERROR 와 같으면 에러. */
int umpireBallNumArr(int ballNumArr[BALL_ARR_LENGTH], int *strikeCount, int *ballCount);
