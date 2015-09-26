#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ballUmpire.h"

int mNumBallArr[BALL_ARR_LENGTH] = { -1, };

int isValidNumBall(int num) {
	int ret = 1;
	int i;

	for (i = 0; i < BALL_ARR_LENGTH; i++) {
		if (*(mNumBallArr + i) == num) {
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
		while (isValidNumBall(num) == 0) {
			num = rand() % MAX_BALL_NUM;
		}
		*(mNumBallArr + i) = num;
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

	printf("\n\n");
}

int umpireNumBallArr(int *numBallArr, int *strikeCount, int *ballCount) {
	int ret = ERROR;
	if (mNumBallArr == -1) {
		printf("게임 준비가 되지않았습니다. setupNewGame() 을 호출해주세요");
	}
	else {
		int i;
		int j;
		ret = SUCCESS;

		for (i = 0; i < BALL_ARR_LENGTH; i++) {
			for (j = 0; j < BALL_ARR_LENGTH; j++) {
				if (*(numBallArr + i) == *(mNumBallArr + j)) {
					if (i == j)
						*strikeCount = *(strikeCount) + 1;
					else
						*ballCount = *(ballCount) + 1;
				}
			}
		}

		printResult(strikeCount, ballCount);
	}
	return ret;
}