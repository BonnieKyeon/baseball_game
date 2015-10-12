#include <stdio.h>
#include "ballUmpire.h"
#include "catcher.h"

#define MAX_CHANCE_COUNT 10
#define MAX_BALL_NUM 9
#define NUM_BALL_ARR_LENGTH 3

void printUsage();
void printUsageAIMode();
void startNewGame();

int main(int argc, char* argv[]) {

	int gameMode;

	printf("���� �߱����� \n\n");
	printf("���� ��带 �Է����ּ��� \n");
	printf("0 : ��ǻ�Ͱ� ����, ������ ����, 1: ������ ����, ��ǻ�Ͱ� ���� \n");
	
	scanf_s("%1d", &gameMode);
	printf("\n");
	if (gameMode == 0) {
		printUsage();
		char c = 'y';
		while (c == 'y' || c == 'Y') {
			startNewGame();

			printf("������ �ٽ� �����Ͻðڽ��ϱ�? ( Y / N ) : ");

			c = getche();
			printf("\n\n");
		}
	}
	else if(gameMode == 1){ //ai
		printUsageAIMode();
	}

	system("pause");
	return 0;
}

void startNewGame() {
	printf("���� ����! \n\n");
	int* aNumBallArr[NUM_BALL_ARR_LENGTH] = { -1, };
	getNewNumBallArr(aNumBallArr, NUM_BALL_ARR_LENGTH, MAX_BALL_NUM);
	int ret = 0;
	int chanceCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numBallArr[NUM_BALL_ARR_LENGTH] = { -1, };

	while (1) {
		printf("%d ��° ��ȸ�Դϴ�. \n", chanceCount + 1);
		printf("�ߺ������ʴ� ���� �ڸ� ���ڸ� �� �� �Է��ϼ���. \n");
		scanf_s("%1d %1d %1d", numBallArr, numBallArr + 1, numBallArr + 2);

		ret = umpireNumBallArr(aNumBallArr, numBallArr, &strikeCount, &ballCount, NUM_BALL_ARR_LENGTH);
		if (ret == ERROR) {
			printf("���� ����. \n");
			return;
		}
		else {
			if (strikeCount == NUM_BALL_ARR_LENGTH) {
				printf("�¸��߽��ϴ�! \n");
				return;
			}
			else {
				strikeCount = 0;
				ballCount = 0;
				chanceCount++;

				if (chanceCount == MAX_CHANCE_COUNT) {
					printf("���ѵ� ��ȸ �ȿ� ������ ���߽��ϴ� \n");
					printf("���� ����. \n");
					return;
				}
			}
		}
	}
}

void printUsage() {
	printf("��ǻ�Ͱ� ����, ������ ���� \n");
	printf("���ѵ� ��ȸ (%dȸ) ���� �������κ��� 3 Strike �� ���� �¸� \n", MAX_CHANCE_COUNT);
	printf("-------- \n");
	printf("�Է� ���� : ����1 ���� ����2 ���� ����3\n");
	printf("���� : 3 1 9\n");
	printf("-------- \n");
}

void printUsageAIMode() {
	printf("������ ����, ��ǻ�Ͱ� ���� \n");
	printf("������ �ߺ������ʴ� �� ���� ���ڸ� ���Ѵ�. \n��ǻ�Ͱ� �� ���� ���ڸ� �����ϸ� ���ص� ���ڿ� ���ؼ� Strike �� Ball�� ������ �����ش�. \n");
	printf("-------- \n");
	printf("�Է� ���� : strikeCount ���� ballCount\n");
	printf("���� : 1 2\n");
	printf("-------- \n");
}
