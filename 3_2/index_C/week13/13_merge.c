#include <stdio.h>

#define MAX 10

void Merge(int *, int *, int, int, int);
void MergeSort(int *, int *, int, int);


int main()
{
	int i;
	srand(time(NULL));
	int A[MAX];
	for (i = 0; i < MAX; i++) {			//1000 이하 랜덤 배열 생성
		A[i] = (rand() % 1000);
	}
	int B[MAX] = { 0,};

	printf("초기 : ");
	for (i = 0; i < MAX; i++)
		printf("%d ", A[i]);
	puts("\n");

	MergeSort(A, B, 0, MAX - 1);

	printf("result : ");
	for (i = 0; i < MAX; i++)
		printf("%d ", A[i]);
	puts("\n");

	return 0;
}

void Merge(int *A, int *B, int left, int mid, int right)
{	//최소 원소 2개부터 합병
	int LP, RP, BP, i;
	LP = left;
	RP = mid + 1;
	BP = left;

	while (BP <= right) {

		if (RP > right)	//오른쪽 배열 전부 복사 되었을 경우 왼쪽 배열 나머지 그대로 복사해 넣어준다
			B[BP++] = A[LP++];
		else if (LP > mid)	//왼쪽 배열 전부 복사되었을 경우 오른쪽 배열 나머지 그대로 복사해 넣어준다
			B[BP++] = A[RP++];

		else if (A[LP] <= A[RP]) {	//A끼리 비교하는 듯 보이나 이미 정렬이 완료된 나눠진 두 배열을 비교하는 과정
			//왼쪽 배열의 앞부분보다 오른쪽 부분의 앞부분이 더 클 때
			B[BP++] = A[LP++];	//새로 생성하는 배열(B)의 해당 순서에 왼쪽 배열의 앞부분 복사
			printf("swap : ");
			for (int t = 0; t < MAX; t++)
				printf("%d ", B[t]);
			puts("\n");
		}
		else if (A[LP] >= A[RP]) {
			//왼쪽 배열의 앞부분보다 오른쪽 부분의 앞부분이 더 작을 때
			B[BP++] = A[RP++];	//새로 생성하는 배열(B)의 해당 순서에 오른쪽 배열의 앞부분 복사
			printf("swap : ");
			for (int t = 0; t < MAX; t++)
				printf("%d ", B[t]);
			puts("\n");
		}

	}
	printf("move : ");
	for (int t = 0; t < MAX; t++)
		printf("%d ", B[t]);
	puts("\n");
	for (i = left; i <= right; i++)
		A[i] = B[i];
}

void MergeSort(int *A, int *B, int left, int right)
{
	int mid;

	if (left < right) {
		mid = (left + right) / 2;	//가운데 기준 분할
		MergeSort(A, B, left, mid);
		MergeSort(A, B, mid + 1, right);

		//합병정렬
		Merge(A, B, left, mid, right);
	}
}
