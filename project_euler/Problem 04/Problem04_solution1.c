
// This code is for 1st solution of Project Euler Problem 4.
// redjo99 updated in 10.June.

#include<stdio.h>

void findPalindromicNum(int n) {
	int digit = 0;
	int is_palindromic;
	int max = n * n;
	int number, cnt;
	while (max > 0) {
		max /= 10;
		digit++;
	}
	int* digits = malloc(sizeof(int)*digit);
	for (int i = n; i >= 100; i--) {
		for (int j = n; j >= 100; j--) {
			number = i * j;
			cnt = 0;
			while (number > 0) {
				digits[cnt++] = number % 10;
				number /= 10;
			}
			cnt--;
			is_palindromic = 1;
			for(int k=0;k<cnt/2;k++) {
				if (digits[k] != digits[cnt - k]) {
					is_palindromic = 0;
					break;
				}
			}
			if (is_palindromic == 1) {
				printf("%d\n", i*j);
			}
		}
	}

	free(digits);
}

int main(void) {
	int n, palindromic_num;
	printf("This program finds a palindromic number with given condition\n");
	printf("(made from the product of two 3-digit numbers which is less than N)\n");
	printf("Input N: ");
	scanf("%d", &n);
	printf("The palindromic numbers are:\n");
	findPalindromicNum(n);

	return 0;
}
