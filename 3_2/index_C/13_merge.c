#include <stdio.h>

#define MAX 10

void Merge(int *, int *, int, int, int);
void MergeSort(int *, int *, int, int);


int main()
{
	int i;
	srand(time(NULL));
	int A[MAX];
	for (i = 0; i < MAX; i++) {			//1000 ���� ���� �迭 ����
		A[i] = (rand() % 1000);
	}
	int B[MAX] = { 0,};

	printf("�ʱ� : ");
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
{	//�ּ� ���� 2������ �պ�
	int LP, RP, BP, i;
	LP = left;
	RP = mid + 1;
	BP = left;

	while (BP <= right) {

		if (RP > right)	//������ �迭 ���� ���� �Ǿ��� ��� ���� �迭 ������ �״�� ������ �־��ش�
			B[BP++] = A[LP++];
		else if (LP > mid)	//���� �迭 ���� ����Ǿ��� ��� ������ �迭 ������ �״�� ������ �־��ش�
			B[BP++] = A[RP++];

		else if (A[LP] <= A[RP]) {	//A���� ���ϴ� �� ���̳� �̹� ������ �Ϸ�� ������ �� �迭�� ���ϴ� ����
			//���� �迭�� �պκк��� ������ �κ��� �պκ��� �� Ŭ ��
			B[BP++] = A[LP++];	//���� �����ϴ� �迭(B)�� �ش� ������ ���� �迭�� �պκ� ����
			printf("swap : ");
			for (int t = 0; t < MAX; t++)
				printf("%d ", B[t]);
			puts("\n");
		}
		else if (A[LP] >= A[RP]) {
			//���� �迭�� �պκк��� ������ �κ��� �պκ��� �� ���� ��
			B[BP++] = A[RP++];	//���� �����ϴ� �迭(B)�� �ش� ������ ������ �迭�� �պκ� ����
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
		mid = (left + right) / 2;	//��� ���� ����
		MergeSort(A, B, left, mid);
		MergeSort(A, B, mid + 1, right);

		//�պ�����
		Merge(A, B, left, mid, right);
	}
}