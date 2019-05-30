//sorting of array list using selection sort
#include <stdio.h>

/*Displays the array, passed to this method*/
void display(int* arr, int n){
    
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
}


/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 size --- Array Size
*/
void selectionSort(int* arr, int size){
    
	int tmp;

    for(int i=0; i<size - 1; i++) {
        int min_index = i;

        for(int j=i+1; j<size; j++) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        
	tmp = arr[min_index];
	arr[min_index] = arr[i];
	arr[i] = tmp;

    }
}

int main(void) {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n); // E.g. 8
    
    printf("Enter the elements of the array\n");
    int i;
    int* arr = (int*)malloc( n * sizeof(int) );
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i] );
    }
    
    printf("Original array: ");
    display(arr, n);                   // Original array : 10 11 9 8 4 7 3 8
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    display(arr, n);                // Sorted array : 3 4 7 8 8 9 10 11
    
    return 0;
}

