#include <stdio.h>

#define MAX 8

void BubbleSort(int*, int, int, int*);
void swap(int*, int, int*);

int main() {

	srand(time(NULL));
	int A[MAX];
	for (int i = 0; i < MAX; i++) {			//1000 ���� ���� �迭 ����
		A[i] = (rand() % 1000);				
	}
	
	int i = 0, j, swp_num = 0;	//swp_num�� ���° ������ �������� Ȯ���ϱ� ���� ���

	puts("Array A");
	for (j = 0; j < MAX; j++) {
		printf("%d ", A[j]);
	}
	puts("\n");
	j = 1;

	BubbleSort(A, i,j, &swp_num);
}

void BubbleSort(int* pa, int i,int j, int *swp_num) {

	int k;

	if (j > MAX - 1) return;	//���� �Ϸ�� ����

	if (*(pa + i) > * (pa + i + 1)) {	//�պ��� �ڰ� �� ���� ���
		swap(pa, i, swp_num);
		printf("step %d_%d\n", j, *swp_num);
		for (k = 0; k < MAX; k++) {
			printf("%d ", *(pa + k));
		}
		puts("\n");
	}

	i++;

	if (i > MAX-1 - j) {	//�ڸ� ���� ���κе� ���� ���� �˻��
		++j;	//���� �� ǥ��
		i = 0;	//ó������ �ٽ� �˻�	
		*swp_num = 0;	//���� Ƚ�� �ʱ�ȭ
	}

	BubbleSort(pa, i, j, swp_num);
}

void swap(int* pa, int i, int *swp_num) {	//�� �� ���� ��ȯ
	int a = *(pa + i);
	int b = *(pa + i + 1);
	*(pa + i) = b;
	*(pa + i + 1) = a;
	++*swp_num;	//��ȯ �� �� �ߴ��� ǥ��
}