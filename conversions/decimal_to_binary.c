#include <stdio.h>
#include <stdlib.h>

#define MAXBITS 32

int main()
{

    // input of the user
    int inputNumber;

    // for the remainder
    int re;

    // contains the bits 0/1
    int bits[MAXBITS];

    // for the loops
    int i = 0;
    int j;

    // initialize bits[]
	
    for(j = 0; j < MAXBITS; j++)
	bits[j] = 0;



    printf("Converter decimal --> binary\n\n");

    // reads a decimal number from the user.
    printf("Enter a positive integer number: ");
    scanf("%d",&inputNumber);

    // make sure the input number is a positive integer.
    if (inputNumber < 0)
    {
	inputNumber = -inputNumber;

	while(inputNumber > 0)
	{
	     // computes the remainder by modulo 2
             re = inputNumber % 2;
	     
	     // computes the quotient of division by 2
             inputNumber = inputNumber / 2;

	     bits[i] = re;
             i++;	
	}
	
	// 1's complement
	for(j = 0; j < 32; j++)
	{
	     if(bits[j] == 0)
		bits[j] = 1;		
	     else
		bits[j] = 0;
	}	
	
	// 2's complement
	for(j = 0; j < 32; j++)
	{
	     if(bits[j] == 0)
	     {
		bits[j] = 1;	
		break;
	     }

	     else
		bits[j] = 0;
	}

	
	printf("\n\n The number in binary is: ");

        // iterates backwards over all bits
        for(j = i - 1; j >= 0; j--)
        {
           printf("%d", bits[j]);
        }

        printf("\n");

    }


    // for the case the input number is 0
    else if (inputNumber == 0)
        printf("0\n");

    else
    {
         // actual processing
         while(inputNumber > 0)
         {

             // computes the remainder by modulo 2
             re = inputNumber % 2;

             // computes the quotient of division by 2
             inputNumber = inputNumber / 2;

             bits[i] = re;
             i++;
         }

       	 printf("\n\n The number in binary is: ");

         // iterates backwards over all bits
         for(j = i - 1; j >= 0; j--)
         {
            printf("%d", bits[j]);
         }

         printf("\n");
         
     }
    
    return 0;
}

