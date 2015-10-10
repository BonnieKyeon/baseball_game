#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ballUmpire.h"

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

int umpireNumBallArr(int *numBallArr1, int *numBallArr2, int *strikeCount, int *ballCount, int arrLength) {
	int ret = ERROR;
	if (numBallArr1 == -1 || numBallArr2 == -1) {
		printf("Error!");
	}
	else {
		int i, j;
		ret = SUCCESS;
		int sCount = 0;
		int bCount = 0;

		for (i = 0; i < arrLength; i++) {
			for (j = 0; j < arrLength; j++) {
				if (*(numBallArr1 + i) == *(numBallArr2 + j)) {
					if (i == j)
						sCount++;
					else
						bCount++;
				}
			}
		}

		*strikeCount = sCount;
		*ballCount = bCount;

		printResult(strikeCount, ballCount);
	}
	return ret;
}