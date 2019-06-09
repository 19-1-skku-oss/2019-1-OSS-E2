#include <stdio.h>

int linearsearch(int* arr, int size, int val)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] == val)
			return 1;
	}
	
	return 0;
}

void main(){
	int s,i,v;
	printf("Enter the size of the array: ");
	scanf("%d", &s);

	int* a = (int*)malloc(s * sizeof(int));
	printf("Enter the contents for an array of size %d: ", s);
	for (i = 0; i < s; i++)	scanf("%d", &a[i]);// accepts the values of array elements until the loop terminates//

	printf("Enter the value to be searched: ");
	scanf("%d", &v);
	if (linearsearch(a, s, v))
		printf("Value %d is in the array.\n", v);
	else
		printf("Value %d is not in the array.\n", v);
}
