
// This code is for 2nd solution of Project Euler Problem 4.
// redjo99 updated in 11.June.

#include<stdio.h>

int findPalindromicNum(int n, int arr[]) {
	int digit = 0;
	int is_palindromic, palindromic_num = 0;
	int is_duplicated;
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
				is_duplicated = 0;
				for (int k = 0; k < palindromic_num; k++) {
					if (i*j == arr[k]) {
						is_duplicated = 1;
						break;
					}
				}
				if (!is_duplicated) {
					arr[palindromic_num++] = i * j;
				}
			}
		}
	}
	free(digits);

	return palindromic_num;
}

int main(void) {
	int n, palindromic_num;
	printf("This program finds a palindromic number with given condition\n");
	printf("(made from the product of two 3-digit numbers which is less than N)\n");
	printf("Input N: ");
	scanf("%d", &n);
	int* result = malloc(sizeof(int)*n);
	printf("The palindromic numbers are:\n");
	palindromic_num = findPalindromicNum(n, result);
	for (int i = 0; i < palindromic_num; i++) {
		printf("%d\n", result[i]);
	}
	free(result);

	return 0;
}
