#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int max= INT_MIN;

int*arr;


// count sort function 
void count_sort(int* arr, int size, int digit)
{
    int i;
    int result[size];

    // taking count array of size 10
    int count[10];

    // initialize count array
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }

    for(i=0;i<size;i++)
    {
        count[(arr[i]/digit)%10]++;
    }
    
    for(i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }

    for(i=size-1;i>=0;i--)
    {
        result[count[(arr[i]/digit)%10]-1]= arr[i];
        count[(arr[i]/digit)%10]--;
    }
    
    for(i=0;i<size;i++)
    {
        arr[i]=result[i];
    }

}

// radix sort function
void radix_sort(int*arr,int size)
{
    int digit;
    
    for(digit=1;max/digit>0; digit*=10)
    {
        count_sort(arr,size,digit);
    }
}

// Driver program for sorting integer using radix sort
int main()
{
    int n,i;
    printf("Number of elements to sort \n");
    scanf("%d",&n);

    arr=(int*)malloc(sizeof(int) * n);

    printf("Insert the numbers to sort \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]>max)
        {
            max= arr[i];
        }

    }
    printf("Original array: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
    printf("\nSorted array using radix sort: \n");

    radix_sort(arr,n);
    
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    

    return 0;
}