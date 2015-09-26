#include <stdio.h>
#include "ballUmpire.h"

void printUsage();

int main(int argc, char* argv[]) {
	printUsage();

	printf("게임 시작! \n");
	setupNewGame();

	int ret = 0;
	int chanceCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numBallArr[BALL_ARR_LENGTH] = { 0, };

	while (1) {
		printf("%d 번째 기회입니다. \n", chanceCount + 1);
		printf("중복되지않는 세 개의 숫자를 입력하세요. \n");
		scanf_s("%1d %1d %1d", numBallArr, numBallArr + 1, numBallArr + 2);

		ret = umpireNumBallArr(numBallArr, &strikeCount, &ballCount);
		if (ret == ERROR) {
			printf("게임 종료. \n");
			break;
		}
		else {
			if (strikeCount == BALL_ARR_LENGTH) {
				printf("승리했습니다! \n");
				break;
			}
			else {
				strikeCount = 0;
				ballCount = 0;
				chanceCount++;

				if (chanceCount == MAX_CHANCE_COUNT) {
					printf("제한된 기회 안에 맞추지 못했습니다 \n");
					printf("게임 종료. \n");
				}
			}

			
		}
	}

	system("pause");
	return 0;
}

void printUsage() {
	printf("숫자 야구게임! \n");
	printf("제한된 기회 (%d회) 내에 심판으로부터 3 Strike 를 얻어내면 승리 \n", MAX_CHANCE_COUNT);
	printf("-------- \n");
	printf("입력 포맷 : 숫자1 공백 숫자2 공백 숫자3\n");
	printf("예시 : 3 1 9\n");
}
