// This code is for radix sorting
// redjo99 updated in 28.May.

#include<stdio.h>
#include<string.h>

int findmaxdigit(int arr[], int size) {
	int m = arr[0];
	int numdigits = 0;
	for (int i = 0; i < size; i++) {
		if (m < arr[i]) m = arr[i];
	}
	while (m > 0) {
		m /= 10;
		numdigits++;
	}
	return numdigits;
}

void radix(int arr[], int size) {
	int digit=1;
	int maxdigit = findmaxdigit(arr, size);
	for (int i = 0; i < maxdigit; i++) {
		for (int j = 0; j < size; j++) {

		}
	}
}

int main(void) {
	int number[] = { 35,473,121,4456,1,23,7,902,3034 };
	int size = sizeof(number) / sizeof(int);
	radix(number, sizeof(number));
	for (int i = 0; i < size; i++) printf("%d ", number[i]);
	return 0;
}