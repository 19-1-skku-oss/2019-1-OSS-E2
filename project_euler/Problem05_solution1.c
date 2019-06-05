// This code is for 1st solution of Project Euler Problem 5.
// redjo99 updated in 5.June.

#include<stdio.h>

int multiplyprimes(int n) {
	int result = 1;
	int is_prime;

	for (int i = 2; i <= n; i++) {
		is_prime = 1;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime == 1) {
			result *= i;
		}
	}

	return result;
}

int main(void) {
	int n, divisible_num;
	printf("This program finds the smallest positive number that is\n");
	printf("evenly divisible by all of the numbers from 1 to N\n");
	printf("Input N: ");
	scanf("%d", &n);
	divisible_num = multiplyprimes(n);
	printf("The result for %d is %d", n, divisible_num);

	return 0;
}
