// This code is for 2st solution of Project Euler Problem 5.
// redjo99 updated in 6.June.

#include<stdio.h>

int findDivisibleNum(int n) {
	int result;
	int is_divisible = 0;
	int num = n;

	while(!is_divisible) {
		is_divisible = 1;
		for (int i = 1; i <= num; i++) {
			if (n % i != 0) {
				is_divisible = 0;
				break;
			}
		}
		if (is_divisible == 1) {
			result = n;
		}
		n++;
	}

	return result;
}

int main(void) {
	int n, divisible_num;
	printf("This program finds the smallest positive number that is\n");
	printf("evenly divisible by all of the numbers from 1 to N\n");
	printf("Input N: ");
	scanf("%d", &n);
	divisible_num = findDivisibleNum(n);
	printf("The result for %d is %d", n, divisible_num);

	return 0;
}
