#include "catcher.h"
#include <time.h>

int isValidNumBall(int *numBallArr, int arrLength, int num) {
	int ret = 1;
	int i;

	for (i = 0; i < arrLength; i++) {
		if (*(numBallArr + i) == num) {
			ret = 0;
		}
	}

	return ret;
}

void getNewNumBallArr(int *numBallArr, int arrLength, int maxNum) {
	int i;
	srand(time(NULL));
	for (i = 0; i < arrLength; i++) {
		int num = (rand() % maxNum) + 1;
		while (isValidNumBall(numBallArr, arrLength, num) == 0) {
			num = (rand() % maxNum) + 1;
		}
		*(numBallArr + i) = num;
	}
}