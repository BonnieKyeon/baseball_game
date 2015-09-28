#include <stdio.h>
#include "ballUmpire.h"

void printUsage();
void startNewGame();

int main(int argc, char* argv[]) {
	printUsage();

	char c = 'y';
	while (c == 'y' || c == 'Y') {
		startNewGame();

		printf("게임을 다시 시작하시겠습니까? ( Y / N ) : ");

		c = getche();
		printf("\n\n");
	}

	system("pause");
	return 0;
}

void startNewGame() {
	printf("게임 시작! \n\n");
	int* aNumBallArr[BALL_ARR_LENGTH] = { -1, };
	getNewNumBallArr(aNumBallArr);
	int ret = 0;
	int chanceCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numBallArr[BALL_ARR_LENGTH] = { -1, };

	while (1) {
		printf("%d 번째 기회입니다. \n", chanceCount + 1);
		printf("중복되지않는 일의 자리 숫자를 세 개 입력하세요. \n");
		scanf_s("%1d %1d %1d", numBallArr, numBallArr + 1, numBallArr + 2);

		ret = umpireNumBallArr(aNumBallArr, numBallArr, &strikeCount, &ballCount);
		if (ret == ERROR) {
			printf("게임 종료. \n");
			return;
		}
		else {
			if (strikeCount == BALL_ARR_LENGTH) {
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
	printf("숫자 야구게임! \n");
	printf("제한된 기회 (%d회) 내에 심판으로부터 3 Strike 를 얻어내면 승리 \n", MAX_CHANCE_COUNT);
	printf("-------- \n");
	printf("입력 포맷 : 숫자1 공백 숫자2 공백 숫자3\n");
	printf("예시 : 3 1 9\n");
	printf("-------- \n");
}
