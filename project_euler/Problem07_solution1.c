// This code is for 1st solution of Project Euler Problem 7.
// redjo99 updated in 5.June.

#include<stdio.h>

int findnthprime(int n) {
	int prime=1, cnt=0, isprime;
	while (cnt < n) {
		prime++;
		isprime = 1;
		for (int i = 2; i < prime; i++) {
			if (prime%i == 0) {
				isprime = 0;
				break;
			}
		}
		if (isprime == 1) {
			cnt++;
		}
	}
	return prime;
}

int main(void) {
	int n, prime;
	scanf("%d", &n);
	prime = findnthprime(n);
	printf("%dth prime number is %d\n", n, prime);

	return 0;
}
