// This code is for 1st solution of Project Euler Problem 5.
// redjo99 updated in 8.June.

#include<stdio.h>
#include<math.h>

void primesLessThanN(int arr[], int n) {
	int cnt = 0;
	int is_prime;
	for (int i = 2; i <= n; i++) {
		is_prime = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				is_prime = 0;
				break;
			}
		}
		if (is_prime) {
			arr[cnt++] = i;
		}
	}
}

int multiplyprimes(int n) {
	int result = 1;
	int* prime = malloc(sizeof(int)*n);

	
	free(prime);
	return result;
}

int main(void) {
	int n, num_primes, divisible_num;

	printf("This program finds the smallest positive number that is\n");
	printf("evenly divisible by all of the numbers from 1 to N\n");
	printf("Input N: ");
	scanf("%d", &n);
	int* primes = malloc(sizeof(int)*n);

	primesLessThanN(primes, n);
	divisible_num = multiplyprimes(n);

	printf("The result for %d is %d", n, divisible_num);
	free(primes);

	return 0;
}
