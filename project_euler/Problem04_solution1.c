// This code is for 1st solution of Project Euler Problem 4.
// redjo99 updated in 7.June.

#include<stdio.h>

int findPalindromicNum(int n) {
	int digit = 0;
	int result;
	int is_palindromic = 0;
	while (n > 0) {
		n /= 10;
		digit++;
	}
	int* digits = malloc(sizeof(int)*digit);

	free(digits);
	return result;
}

int main(void) {
	int n, palindromic_num;
	printf("This program finds a palindromic number with given condition\n");
	printf("(made from the product of two 3-digit numbers which is less than N)\n");
	printf("Input N: ");
	scanf("%d", &n);
	palindromic_num = findPalindromicNum(n);
	printf("The result for %d is %d", n, palindromic_num);

	return 0;
}
