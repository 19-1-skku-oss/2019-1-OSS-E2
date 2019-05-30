#include<stdio.h>

int decimal(int number, int n, int m) {
	int digit, result;
	int a, b, d;

	for (digit = 0, result = 0; number > 0; digit++) {
		a = number % n;
		b = a;
		number /= n;

		for (d = digit; d > 0; d--) {
			b *= m;
		}
		result += b;
	}
	return result;
}
