#define MAX_BALL_NUM 10
#define BALL_ARR_LENGTH 3
#define MAX_CHANCE_COUNT 10
#define ERROR -1
#define SUCCESS 0

/* ������ �� int�����͹迭�� �޾Ƽ� ���� ä���. */
void getNewNumBallArr(int *numBallArr);

/*	�� int �迭�� ���ڿ� �ڸ��� ���ؼ� strikeCount�� ballCount �� ���� �ٲ��ְ�, ����Ѵ� */
int umpireNumBallArr(int *numBallArr1, int *numBallArr2, int *strikeCount, int *ballCount);
