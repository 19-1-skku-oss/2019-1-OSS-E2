// This code is for playing bulls and cows
// In this code, 4 numbers are required
// redjo99 updated in 4.June.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 4

int PlayBullsAndCows(int arr[], int size) {
	int* guess = malloc(sizeof(int)*size);
	int strike, ball;
	for (int i = 0; i < size; i++) {
		scanf("%d", &guess[i]);
		strike = 0, ball = 0;
		if (guess[i] == arr[i]) {
			strike++;
		}
		else {
			for (int j = 1; j < size; j++) {
				if (guess[i] == arr[j]) {
					ball++;
					break;
				}
			}
		}
	}
	free(guess);
	return strike * 10 + ball;
}

void CreateRandomNumbers(int arr[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
		printf("%d\n", arr[i]);
	}
}

int main(void) {
	int num[MAX];
	int strike, ball, point;

	CreateRandomNumbers(num, MAX);

	printf("There are 4 random numbers(0~9).\nPlease input your guessing numbers in order!\n");
	
	while (strike < MAX) {
		point = PlayBullsAndCows(num, MAX);
		printf("%d strike and %d ball\n", point / 10, point % 10);
	}
	printf("\nCongratulations!");

	return 0;
}
