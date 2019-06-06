#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

	int* ARRAY = nullptr;
	int ARRAY_LENGTH, i, TEMPORARY_ELEMENT;
	int isSorted = 0;
	double MEAN = 0, VARIANCE = 0, STAND;


	printf("Enter the number of Random Numbers(0~99) : ");
	scanf("%d", &ARRAY_LENGTH);
	ARRAY = (int*)malloc(ARRAY_LENGTH * (sizeof(int)));	//We allocate the dedicated memory
	for(i = 0; i < ARRAY_LENGTH; i++) 			//We generate the random numbers
		ARRAY[i] = rand()%100;

	printf("Array : "); //We display them
	for(i = 0; i < ARRAY_LENGTH; i++)
		printf("%d ", ARRAY[i]);

	printf("\nSorted Array : ");				//Then we sort it using Bubble Sort..

	while(!isSorted)
	{ //While our array's not sorted
        	isSorted = 1; //we suppose that it's sorted
        	for(i = 0; i < ARRAY_LENGTH - 1; i++)
		{ //then for each element of the array
			if(ARRAY[i] > ARRAY[i+1])
			 {  // if the two elements aren't sorted
               			 isSorted = 0;    //it means that the array is not sorted
               			 TEMPORARY_ELEMENT = ARRAY[i]; //and we switch these elements using TEMPORARY_ELEMENT
         			 ARRAY[i] = ARRAY[i+1];
            		         ARRAY[i+1] = TEMPORARY_ELEMENT;
     	  		 }
                }
        }
	
	for(i = 0; i < ARRAY_LENGTH; i++)
	{
		printf("%d ",ARRAY[i]);
		MEAN = MEAN + ARRAY[i];
	}
	
	MEAN = MEAN/(double)ARRAY_LENGTH;

	for(i = 0; i < ARRAY_LENGTH; i++)
		VARIANCE = VARIANCE + (pow( (ARRAY[i] - MEAN), 2));

	VARIANCE = VARIANCE / ARRAY_LENGTH;
	STAND = sqrt(VARIANCE);


    	printf("\n\n- Mean is: %lf\n",MEAN);
	printf("- Variance is: %lf\n",VARIANCE);
	printf("- Standard Deviation is: %lf\n",STAND);

}



