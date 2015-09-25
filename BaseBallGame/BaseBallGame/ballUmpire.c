#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ballUmpire.h"

int mBallNumArr[BALL_ARR_LENGTH] = { -1, };

int isValidNumber(int num) {
	int ret = 1;
	int i;

	for (i = 0; i < BALL_ARR_LENGTH; i++) {
		if (*(mBallNumArr + i) == num) {
			ret = 0;
		}
	}

	return ret;
}

void setupNewGame() {
	int i;
	srand(time(NULL));

	for (i = 0; i < BALL_ARR_LENGTH; i++) {
		int num = rand() % MAX_BALL_NUM;
		while (isValidNumber(num) == 0) {
			num = rand() % MAX_BALL_NUM;
		}
		*(mBallNumArr + i) = num;
	}
}

void printResult(int *strikeCount, int *ballCount) {
	if (*strikeCount > 0) {
		printf("%d S ", *strikeCount);
	}

	if (*ballCount > 0) {
		printf("%d B ", *ballCount);
	}

	if (*strikeCount == 0 && *ballCount == 0) {
		printf("Out!!");
	}

	printf("\n");
}

int umpireBallNumArr(int ballNumArr[BALL_ARR_LENGTH], int *strikeCount, int *ballCount) {
	int ret = ERROR;
	if (mBallNumArr == -1) {
		printf("게임 준비가 되지않았습니다. setupNewGame() 을 호출해주세요");
	}
	else {
		//ret = SUCCESS;


		printResult(strikeCount, ballCount);
	}
	return ret;
}