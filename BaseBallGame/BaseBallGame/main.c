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

	printf("숫자 야구게임 \n\n");
	printf("게임 모드를 입력해주세요 \n");
	printf("0 : 컴퓨터가 심판, 유저가 투수, 1: 유저가 심판, 컴퓨터가 투수 \n");
	
	scanf_s("%1d", &gameMode);
	printf("\n");
	if (gameMode == 0) {
		printUsage();
		char c = 'y';
		while (c == 'y' || c == 'Y') {
			startNewGame();

			printf("게임을 다시 시작하시겠습니까? ( Y / N ) : ");

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
	printf("게임 시작! \n\n");
	int* aNumBallArr[NUM_BALL_ARR_LENGTH] = { -1, };
	getNewNumBallArr(aNumBallArr, NUM_BALL_ARR_LENGTH, MAX_BALL_NUM);
	int ret = 0;
	int chanceCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numBallArr[NUM_BALL_ARR_LENGTH] = { -1, };

	while (1) {
		printf("%d 번째 기회입니다. \n", chanceCount + 1);
		printf("중복되지않는 일의 자리 숫자를 세 개 입력하세요. \n");
		scanf_s("%1d %1d %1d", numBallArr, numBallArr + 1, numBallArr + 2);

		ret = umpireNumBallArr(aNumBallArr, numBallArr, &strikeCount, &ballCount, NUM_BALL_ARR_LENGTH);
		if (ret == ERROR) {
			printf("게임 종료. \n");
			return;
		}
		else {
			if (strikeCount == NUM_BALL_ARR_LENGTH) {
				printf("승리했습니다! \n");
				return;
			}
			else {
				strikeCount = 0;
				ballCount = 0;
				chanceCount++;

				if (chanceCount == MAX_CHANCE_COUNT) {
					printf("제한된 기회 안에 맞추지 못했습니다 \n");
					printf("게임 종료. \n");
					return;
				}
			}
		}
	}
}

void printUsage() {
	printf("컴퓨터가 심판, 유저가 투수 \n");
	printf("제한된 기회 (%d회) 내에 심판으로부터 3 Strike 를 얻어내면 승리 \n", MAX_CHANCE_COUNT);
	printf("-------- \n");
	printf("입력 포맷 : 숫자1 공백 숫자2 공백 숫자3\n");
	printf("예시 : 3 1 9\n");
	printf("-------- \n");
}

void printUsageAIMode() {
	printf("유저가 심판, 컴퓨터가 투수 \n");
	printf("유저는 중복되지않는 세 개의 숫자를 정한다. \n컴퓨터가 세 개의 숫자를 제시하면 정해둔 숫자와 비교해서 Strike 와 Ball의 개수를 적어준다. \n");
	printf("-------- \n");
	printf("입력 포맷 : strikeCount 공백 ballCount\n");
	printf("예시 : 1 2\n");
	printf("-------- \n");
}
