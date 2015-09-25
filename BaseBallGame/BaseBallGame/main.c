#include <stdio.h>
#include "ballUmpire.h"

void printUsage();

int main(int argc, char* argv[]) {
	printUsage();

	printf("���� ����! \n");
	setupNewGame();

	int ret = 0;
	int count = 0;
	int strikeCount = 0;
	int ballCount = 0;
	int numballArr[BALL_ARR_LENGTH] = { 0, };

	while (1) {
		printf("%d ��° ��ȸ�Դϴ�. \n", count + 1);
		printf("������ ���ڸ� �Է��ϼ���. \n");
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
	printf("���� �߱�����! \n");
	printf("���ѵ� ��ȸ (%dȸ) ���� �������κ��� 3 Strike �� ���� �¸� \n", CHANCE);
	printf("-------- \n");
	printf("�Է� ���� : ����1 ���� ����2 ���� ����3\n");
	printf("���� : 3 1 9\n");
}
