#include<stdio.h>

//convert number n to m
int convert(int number, int n, int m) {
	int digit, temp, result;
	int a, b, d;

	for (digit = 0, temp = 0; number > 0; digit++) {
		a = number % 10;
		b = a;
		number /= 10;

		for (d = digit; d > 0; d--) {
			b *= n;
		}
		temp += b;
	}

	for (digit = 0,result = 0; temp > 0; digit++) {
		a = temp % m ;
		b = a;
		temp /= m;

		for (d = digit; d > 0; d--) {
			b *= 10;
		}
		result += b;
	}
	return result;
}

int main(void)
{
	int num;
	int n, m;

	printf("Enter the number: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("Please input positive number!");
		printf("Enter the number: ");
		scanf("%d", &num);
	}

	printf("Enter the initial base: ");
	scanf("%d", &n);
	printf("Enter the result base: ");
	scanf("%d", &m);


	num = convert(num, n, m);
	printf("\nConverted number is: %d\n", num);




	return 0;
}
