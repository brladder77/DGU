#include <stdio.h>

#define MAX 8

void BubbleSort(int*, int, int, int*);
void swap(int*, int, int*);

int main() {

	srand(time(NULL));
	int A[MAX];
	for (int i = 0; i < MAX; i++) {			//1000 이하 랜덤 배열 생성
		A[i] = (rand() % 1000);				
	}
	
	int i = 0, j, swp_num = 0;	//swp_num는 몇번째 바퀴의 스왑인지 확인하기 위해 사용

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

	if (j > MAX - 1) return;	//정렬 완료시 종료

	if (*(pa + i) > * (pa + i + 1)) {	//앞보다 뒤가 더 작을 경우
		swap(pa, i, swp_num);
		printf("step %d_%d\n", j, *swp_num);
		for (k = 0; k < MAX; k++) {
			printf("%d ", *(pa + k));
		}
		puts("\n");
	}

	i++;

	if (i > MAX-1 - j) {	//자리 잡은 끝부분들 제외 전부 검사시
		++j;	//바퀴 수 표시
		i = 0;	//처음부터 다시 검사	
		*swp_num = 0;	//스왑 횟수 초기화
	}

	BubbleSort(pa, i, j, swp_num);
}

void swap(int* pa, int i, int *swp_num) {	//앞 뒤 원소 교환
	int a = *(pa + i);
	int b = *(pa + i + 1);
	*(pa + i) = b;
	*(pa + i + 1) = a;
	++*swp_num;	//교환 몇 번 했는지 표시
}
