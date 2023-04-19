#include <stdio.h>
//printing array list code
void PrintArray(int *array, int n)
{
     int i;
     for( i = 0; i < n; ++i)
     printf("%d ", array[i]);
     printf("\n");
}
//main quick sort logic function
void QuickSort(int arr[50], int first, int last)
{
    int i,j,pivot,tmp;
    if(first<last)
    {
         //get pivot element as first
         pivot=first;
         i=first;
         j=last;
         while(i<j)
         {
            // Move left while i(first) < pivot
            while(arr[i]<=arr[pivot] && i<last)
                 i++;
                 // Move right while j(last) > pivot
             while(arr[j]>arr[pivot])
                 j--;
                 if(i<j)
                 {
                     tmp=arr[i];
                     arr[i]=arr[j];
                     arr[j]=tmp;
             }
         }
         tmp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=tmp;
         QuickSort(arr,first,j-1);
         QuickSort(arr,j+1,last);
    }
}

void main()
{
     int array[50], i, n;
     printf("Enter no. of elements: ");
     scanf("%d", &n);
     for (i=0; i<n; i++)
     {
        printf("Enter the element at pos[%d]: ",i);
        scanf ("%d", &array[i]);
     }
     printf("Unsorted elements: \n");
     PrintArray(array, n);
     QuickSort(array, 0,n-1);
     printf("Sorted list after Quick Sort :\n");
     PrintArray(array, n);
}
