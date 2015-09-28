#define MAX_BALL_NUM 10
#define BALL_ARR_LENGTH 3
#define MAX_CHANCE_COUNT 10
#define ERROR -1
#define SUCCESS 0

/* 답으로 쓸 int포인터배열을 받아서 값을 채운다. */
void getNewNumBallArr(int *numBallArr);

/*	두 int 배열의 숫자와 자리를 비교해서 strikeCount와 ballCount 에 값을 바꿔주고, 출력한다 */
int umpireNumBallArr(int *numBallArr1, int *numBallArr2, int *strikeCount, int *ballCount);
