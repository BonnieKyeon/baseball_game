#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ballUmpire.h"

int isValidNumBall(int *numBallArr, int num) {
	int ret = 1;
	int i;

	for (i = 0; i < BALL_ARR_LENGTH; i++) {
		if (*(numBallArr + i) == num) {
			ret = 0;
		}
	}

	return ret;
}

void getNewNumBallArr(int *numBallArr) {
	int i;
	srand(time(NULL));
	for (i = 0; i < BALL_ARR_LENGTH; i++) {
		int num = rand() % MAX_BALL_NUM;
		while (isValidNumBall(numBallArr, num) == 0) {
			num = rand() % MAX_BALL_NUM;
		}
		*(numBallArr + i) = num;
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

int umpireNumBallArr(int *numBallArr1, int *numBallArr2, int *strikeCount, int *ballCount) {
	int ret = ERROR;
	if (numBallArr1 == -1 || numBallArr2 == -1) {
		printf("Error!");
	}
	else {
		int i;
		int j;
		ret = SUCCESS;

		for (i = 0; i < BALL_ARR_LENGTH; i++) {
			for (j = 0; j < BALL_ARR_LENGTH; j++) {
				if (*(numBallArr1 + i) == *(numBallArr2 + j)) {
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