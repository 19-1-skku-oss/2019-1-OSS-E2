#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
	int* a;
	int n, i, j, temp;
	int sum = 0;
	double mean;
	
	clrscr();
	printf("Enter the number of Random Numbers(0 ~ 99) : ");
	scanf("%d",&n);
	a = (int*)malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++)
		a[i] = rand() % 100;
	
	printf("Random Numbers are : ");
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);
	printf("\n");
	
	printf("\nSorted Data: ");
	
	for(i = 0 ; i < n; i++)			// Bubble Sort
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if( a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1]=temp;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
		sum = sum + a[i];
	}
	
	mean = (double)sum / n;
	printf("\n\nMean : %lf", mean);

	return 0;
}


