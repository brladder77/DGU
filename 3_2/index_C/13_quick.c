#include <stdio.h>

#define MAX 8

void QuickSort(int*, int, int);
void swap(int*, int, int);


int main() {

	srand(time(NULL));
	int A[MAX];
	for (int i = 0; i < MAX; i++) {			//1000 이하 랜덤 배열 생성
		A[i] = (rand() % 1000);
	}

	printf("초기 : ");
	for (int i = 0; i < MAX; i++) {
		printf("%d ", A[i]);
	}
	puts("\n");

	QuickSort(A, 0, MAX-1);										//put A in function SelectionSort
	
	printf("result : ");											//check the first state of A
	for (int t = 0; t < MAX; t++)
		printf("%d ", A[t]);
	puts("\n");

	return 0;
}

void QuickSort(int *A, int L, int R) {
	int left = L, right = R;
	int value = A[L];			//set value
	int temp;
	do
	{
		while (A[left] < value)		//untill find smaller one than value
			left++;
		while (A[right] > value)		//untill find bigger one than value
			right--;
		if (left <= right) {			//if left and right doesn't meet
			swap(A, left, right);
			printf("swap 발생 : ");
			for (int t = 0; t < MAX; t++)
				printf("%d ", A[t]);
			puts("\n");
			left++;
			right--;
		}
	} while (left <= right);	//untill left and right meet

	if (L < right)
		QuickSort(A, L, right);				//recursive(in left box)

	if (left < R)
		QuickSort(A, left, R);	//recursive(in right box and change pivot to right box min)
}

void swap(int* pa, int i, int min) {
	int a = *(pa + i);
	int b = *(pa + min);
	*(pa + i) = b;
	*(pa + min) = a;
}