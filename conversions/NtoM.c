#include<stdio.h>

//convert number n to m
int convert(int number, int n, int m) {
	int digit, result;
	int a, b, d;

	for (digit = 0, result = 0; number > 0; digit++) {
		a = number % m;
		b = a;
		number /= m;

		for (d = digit; d > 0; d--) {
			b *= n;
		}
		result += b;
	}
	return result;
}

