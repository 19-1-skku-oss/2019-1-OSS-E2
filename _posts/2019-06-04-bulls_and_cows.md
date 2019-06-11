---
title: Bulls_and_cows
date: 2019-06-04
---

Writing the Bulls_and_cows

## Bulls_and_cows
Create the bulls_and_cows ('숫자야구' in Korean), and update two time by changing function return type, changing, initial variable value, respectively.

```C
// This code is for playing bulls and cows
// In this code, 4 numbers are required
// redjo99 updated in 4.June.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 4

void PlayBullsAndCows(int arr[], int size) {
	int* guess = malloc(sizeof(int)*size);
	int strike, ball;

	for (int i = 0; i < size; i++) {
		scanf("%d", &guess[i]);
		strike = 0, ball = 0;
		if (guess[i] == arr[i]) {
			strike++;
		}
	}

	free(guess);
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

	CreateRandomNumbers(num, MAX);

	printf("There are 4 random numbers(0~9).\nPlease input your guessing numbers in order!\n");
	PlayBullsAndCows(num, MAX);

	return 0;
}
```
