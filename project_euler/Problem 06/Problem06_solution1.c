// This code is for 1st solution of Project Euler Problem 6.
// redjo99 updated in 5.June.

#include<stdio.h>

int abs(int a, int b) {
	int result;
	result = a - b;
	if (result < 0) {
		result *= -1;
	}

	return result;
}

int calculate(int n) {
	int sum_of_squares = 0;
	int sum = 0;
	int square_of_sum;
	int difference;
	
	for (int i = 1; i <= n; i++) {
		sum_of_squares += i * i;
	}

	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	square_of_sum = sum * sum;

	difference = abs(sum_of_squares, square_of_sum);

	return difference;
}

int main(void) {
	int n, result;
	printf("This program is for calculate difference of following two numbers.\n");
	printf("1. Sum of the squares of the first N natural numbers\n");
	printf("2. Square of the sum of the first N natural numbers\n");
	printf("Please input N: ");
	scanf("%d", &n);
	result = calculate(n);
	printf("The result is %d\n", result);

	return 0;
}
