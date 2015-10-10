#define ERROR -1
#define SUCCESS 0

/*	numBallArr1 : 비교할 arr1
	numBallArr2 : 비교할 arr2
	strikeCount : 비교해서 나온 strike count를 넣을 int형 변수를 가리키는 포인터
	ballCount : 비교해서 나온 ball count를 넣을 int형 변수를 가리키는 포인터
	arrLength : 비교할 arr의 길이 */
int umpireNumBallArr(int *numBallArr1, int *numBallArr2, int *strikeCount, int *ballCount, int arrLength);
