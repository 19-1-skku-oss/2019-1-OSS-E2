//sorting of array list using bubble sort
#include <stdio.h>

/*Displays the array, passed to this method*/
void display(int arr[], int n){
    
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
}


/*This is where the sorting of the array takes place
 arr[] --- Array to be sorted
 length --- Array Size
*/
void bubbleSort(int* arr, int size){
    
    int tmp;

    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j]>arr[j+1]) {
                tmp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = tmp;
            }
        }
    }
}

int main(void) {
    int length;
    printf("Enter size of array: ");
    scanf("%d", &length); // E.g. 8
    
    printf("Enter the elements of the array:\n");
    int i;
    int* arr = (int*)malloc(length * sizeof(int));
    for(i = 0; i < length; i++){
        scanf("%d", &arr[i] );
    }
    
    printf("Original array: ");
    display(arr, length);                   // Original array : 10 11 9 8 4 7 3 8
    
    bubbleSort(arr, length);
    
    printf("Sorted array: ");
    display(arr, length);                // Sorted array : 3 4 7 8 8 9 10 11
    
    return 0;
}

