// This code is for 1st solution of Project Euler Problem 7.
// redjo99 updated in 9.June.

#include<stdio.h>
#include<math.h>

int primesLessThanN(int arr[], int n) {
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

	return cnt;
}

void multiplyPrimes(int arr[], int newarr[], int n, int prime_num) {
	int num, cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= prime_num; j++) {
			newarr[j] = 0;
			num = i;
			if (num > 1) {
				while (num%arr[j] == 0) {
					num /= arr[j];
					cnt++;
				}
				if (cnt > newarr[j]) {
					newarr[j] = cnt;
				}
			}
			else {
				break;
			}
		}
	}
}

int lastCalculation(int arr[], int newarr[], int prime_num) {
	int result = 1, sub_result = 1;
	for (int i = 0; i < prime_num; i++) {
		for (int j = 0; j < newarr[i]; j++) {
			sub_result *= arr[i];
		}
		result *= sub_result;
	}

	return result;
}

int main(void) {
	int n, num_primes, result;

	printf("This program finds the smallest positive number that is\n");
	printf("evenly divisible by all of the numbers from 1 to N\n");
	printf("Input N: ");
	scanf("%d", &n);
	
	int* primes = malloc(sizeof(int)*n);
	num_primes = primesLessThanN(primes, n);
	int* cnt_primes = malloc(sizeof(int)*num_primes);
	multiplyPrimes(primes,cnt_primes, n, num_primes);
	result = lastCalculation(primes, cnt_primes, num_primes);

	printf("The result for %d is %d", n, result);
	free(cnt_primes);
	free(primes);

	return 0;
}
