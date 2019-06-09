    #include <stdio.h>
     
    int BinarySearch(int* arr, int n, int search)
    {
        int first = 0;
        int last = n - 1;
        int middle = (first+last)/2;
     
        while (first <= last)
        {
           if (array[middle] < search)
              first = middle + 1;    
           else if (array[middle] == search)
           {
              return middle + 1;
              break;
           }
           else
              last = middle - 1;
     
           middle = (first + last)/2;
        }
        if (first > last)
           return -1;
    }


    int main()
    {
       int c, first, last, middle, n, search, array[100];
     
       printf("Enter number of elements : ");
       scanf("%d",&n);
     
       printf("Enter %d integers\n", n);
     
       for (c = 0; c < n; c++)
          scanf("%d", &array[c]);
     
       printf("Enter value to find : ");
       scanf("%d", &search);
     
       if(BinarySearch(arrary, n, search) != -1)
           printf("%d found at location %d.\n", search, BinarySearch(arrary, n, search));
       else
           printf("Not found! %d isn't present in the list.\n", search);
    }


