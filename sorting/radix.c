// This code is for radix sorting
// redjo99 updated in 29.May.

#include<stdio.h>

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

int localmin(int arr[], int init, int final) {
	int m = init;
	for (int i = init; i < final; i++) {
		if (arr[m] > arr[i]) m = i;
	}
	return m;
}

void radix(int arr[], int size) {
	int digit=1;
	int* copy = malloc(sizeof(int)*size);
	int* dig=malloc(sizeof(int)*size);
	int absm, locm;
	int maxdigit = findmaxdigit(arr, size);
	for (int i = 0; i < size; i++) {
		copy[i] = arr[i];
	}
	for (int i = 0; i < maxdigit; i++) {
		for (int j = 0; j < size; j++) {
			dig[j] = copy[j] % 10;
			copy[j] /= 10;
		}
		for (int j = 0; j < size; j++) {
			absm = j;
			locm = localmin(dig, j+1, size);
			if (dig[absm] > dig[locm]) {
				int temp = dig[absm];
				dig[absm] = dig[locm];
				dig[locm] = temp;
				temp = copy[absm];
				copy[absm] = copy[locm];
				copy[locm] = temp;
				temp = arr[absm];
				arr[absm] = arr[locm];
				arr[locm] = temp;
			}
		}
	}
	free(copy);
	free(dig);
}

int main(void) {
	int number[] = { 35,473,121,4456,1,23,7,902,3034 };
	int size = sizeof(number) / sizeof(int);
	radix(number, sizeof(number));
	for (int i = 0; i < size; i++) printf("%d ", number[i]);
	return 0;
}