#include <stdio.h>
#include "ballUmpire.h"

void printUsage();

int main(int argc, char* argv[]) {
	printUsage();

	printf("���� ����! \n");
	setupNewGame();

	int ret = 0;
	int chanceCount = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numBallArr[BALL_ARR_LENGTH] = { 0, };

	while (1) {
		printf("%d ��° ��ȸ�Դϴ�. \n", chanceCount + 1);
		printf("�ߺ������ʴ� �� ���� ���ڸ� �Է��ϼ���. \n");
		scanf_s("%1d %1d %1d", numBallArr, numBallArr + 1, numBallArr + 2);

		ret = umpireNumBallArr(numBallArr, &strikeCount, &ballCount);
		if (ret == ERROR) {
			printf("���� ����. \n");
			break;
		}
		else {
			if (strikeCount == BALL_ARR_LENGTH) {
				printf("�¸��߽��ϴ�! \n");
				break;
			}
			else {
				strikeCount = 0;
				ballCount = 0;
				chanceCount++;

				if (chanceCount == MAX_CHANCE_COUNT) {
					printf("���ѵ� ��ȸ �ȿ� ������ ���߽��ϴ� \n");
					printf("���� ����. \n");
				}
			}

			
		}
	}

	system("pause");
	return 0;
}

void printUsage() {
	printf("���� �߱�����! \n");
	printf("���ѵ� ��ȸ (%dȸ) ���� �������κ��� 3 Strike �� ���� �¸� \n", MAX_CHANCE_COUNT);
	printf("-------- \n");
	printf("�Է� ���� : ����1 ���� ����2 ���� ����3\n");
	printf("���� : 3 1 9\n");
}
