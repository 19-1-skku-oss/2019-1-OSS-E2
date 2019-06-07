#include<stdio.h>

//convert number n to m
//This function only can convert when N and M are smaller than 10.
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
int main(void){
	int num, n, m;

	printf("Enter the number: ");
	scanf("%d", &num);

	if (num < 0) {
		printf("Please input positive number!");
		printf("Enter the number: ");
		scanf("%d", &num);
	}

	printf("Enter the initial base: ");
	if (n < 0 || n > 11) {
		printf("The base number should be bigger then 0, smaller then 11!");
		printf("Enter the number: ");
		scanf("%d", &n);
	}
	
	printf("Enter the result base: ");
	if (m < 0 || m > 11) {
		printf("The base number should be bigger then 0, smaller then 11!");
		printf("Enter the number: ");
		scanf("%d", &m);
	}
	
	num = convert(num, n, m);
	printf("\nConverted number is: %d\n", num);

	return 0;
}
