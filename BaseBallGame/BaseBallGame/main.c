#include <stdio.h>
#include "ballUmpire.h"

void printUsage();

int main(int argc, char* argv[]) {
	printUsage();

	printf("게임 시작! \n");
	setupNewGame();

	int ret = 0;
	int count = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numballArr[BALL_ARR_LENGTH] = { 0, };

	while (1) {
		printf("%d 번째 기회입니다. \n", count + 1);
		printf("세개의 숫자를 입력하세요. \n");
		scanf_s("%1d %1d %1d", numballArr, numballArr + 1, numballArr + 2);

		ret = umpireBallNumArr(numballArr, &strikeCount, &ballCount);
		if (ret == ERROR) {
			break;
		}

	}

	system("pause");
	return 0;
}

void printUsage() {
	printf("숫자 야구게임! \n");
	printf("제한된 기회 (%d회) 내에 심판으로부터 3 Strike 를 얻어내면 승리 \n", CHANCE);
	printf("-------- \n");
	printf("입력 포맷 : 숫자1 공백 숫자2 공백 숫자3\n");
	printf("예시 : 3 1 9\n");
}
