#include<stdio.h>
#include<stdlib.h>
#include <time.h>


void swap(int *a, int *b)
{
   int t = *a;
   *a = *b;
   *b = t;
}



int partition_first_as_pivot(int arr[] ,int low , int high)
{
   int i, j, x;
   x = arr[low];
   i = low;

   for(j=low+1; j<= high; j++)
   {
       if(arr[j]<= x)
       {
           i++;
           swap(&arr[j], &arr[i]); 
       }
   }
   swap(&arr[i],&arr[low]);

   return i;
}

int partition_random_pivot(int arr[], int low, int high)
{
   int x;
   int n = rand();
   x = low + n % (high-low+1);
   swap(&arr[low], &arr[x]);
   return partition_first_as_pivot(arr,low,high);
}

int partition_as_median(int arr[], int low, int high)
{
   int mid ;
   mid = (high-low+1)/2;
   if(arr[mid] < arr[low])
   {
       swap(&arr[low],&arr[mid]);
   }
   if(arr[high] < arr[mid])
   {
       swap(&arr[high],&arr[mid]);

   }
   if(arr[high] < arr[low])
   {
       swap(&arr[low],&arr[high]);

   }
   swap(&arr[mid], &arr[low]);
   return partition_first_as_pivot(arr,low,high);

}

int partition_as_median1(int arr[], int low, int high)
{
   int m;
   m = (high-low+1)/2;
   int f = (high-low+1)/4;
   int l = 3*(high-low+1)/4;

   if(arr[m] < arr[f])
   {
       swap(&arr[f],&arr[m]);
   }
   if(arr[l] < arr[m])
   {
       swap(&arr[m],&arr[l]);

   }
   if(arr[l] < arr[f])
   {
       swap(&arr[f],&arr[l]);

   }
   swap(&arr[m], &arr[low]);
   return partition_first_as_pivot(arr,low,high);
  

}

void quicksort(int arr[], int low, int high, int d)
{
   if(low< high)
   {
       int pi;
       switch(d)
       {
           case 0:
           pi = partition_first_as_pivot(arr ,low, high);
           break;
       

           case 1:
           pi = partition_random_pivot(arr,low,high);
           break;

           case 2:
           pi = partition_as_median(arr,low,high);
           break;

           case 3:
           pi = partition_as_median1(arr,low,high);
           break;
      
       }
  
      quicksort(arr, low ,pi-1 ,d);
      quicksort(arr,pi+1, high, d);
   }
}

int main()
{   int k;
   int choice;
   int n;
   printf("Enter size of array \n");
   scanf("%d", &n);
   int arr[n];
   for(int i=0; i<n; i++)
   {
       arr[i]= rand()%100;
   }
  
   printf("Displaying the original arrray \n ");
   for(int i=0;i<n;i++)
   {
   printf("%d ",arr[i]);
   }
   clock_t beg;
   clock_t end;
   double t = 0.0;
   while(1)
   {
        printf("\n\n Enter chioce quicksort using ;-\n\t0\t\t first as pivot. \n\t1\t\t random number as pivot.");
        printf("\n\t2\t\t using median of 3(first, middle ,last).");
        printf("\n\t3\t\t using median of 3(n/4th, middle , 3n/4th). \n4\t\t exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
            printf("Quick sort on unsorted array using first element as Pivot \n\t");
            beg = clock();
            quicksort(arr ,0, n-1,0);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of unsorted array :%f seconds \n", t);

            beg = clock();
            quicksort(arr ,0, n-1,0);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of sorted array :%f seconds \n", t);
          
            k=n/4;
            for(int i=0;i< k; k*=4)
            {
                swap(&arr[i], &arr[i+4]);
            }
            beg = clock();
            quicksort(arr ,0, n-1,0);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of almost sorted array :%f seconds \n", t);

            break;

            case 1:
            printf("Quick sort on unsorted array using random element as Pivot \n\t");
            beg = clock();
            quicksort(arr ,0, n-1,1);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of unsorted array :%f seconds \n", t);

            beg = clock();
            quicksort(arr ,0, n-1,1);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of sorted array :%f seconds \n", t);
          
            k=n/4;
            for(int i=0;i< k; k*=4)
            {
                swap(&arr[i], &arr[i+4]);
            }
            beg = clock();
            quicksort(arr ,0, n-1,1);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of almost sorted array :%f seconds \n", t);

            break;
            exit(0);

            case 2:
            printf("Quick sort on unsorted array using median (first,middle,last) element as Pivot \n");
            beg = clock();
            quicksort(arr ,0, n-1,2);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of unsorted array :%f seconds \n", t);

            beg = clock();
            quicksort(arr ,0, n-1,2);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of sorted array :%f seconds \n", t);
          
            k=n/4;
            for(int i=0;i< k; k*=4)
            {
                swap(&arr[i], &arr[i+4]);
            }
            beg = clock();
            quicksort(arr ,0, n-1,2);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of almost sorted array :%f seconds \n", t);
            break;

            case 3:
            printf("Quick sort on unsorted array using median (n/4, middle, 3n/4) element as Pivot \n");
            beg= clock();
            quicksort(arr ,0, n-1,3);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of unsorted array :%f seconds \n", t);

            beg = clock();
            quicksort(arr ,0, n-1,3);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of sorted array :%f seconds \n", t);
          
            k=n/4;
            for(int i=0;i< k; k*=4)
            {
                swap(&arr[i], &arr[i+4]);
            }
            beg = clock();
            quicksort(arr ,0, n-1,3);
            end = clock();
            t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
            printf("\ntotal time to sort elements of almost sorted array :%f seconds \n", t);
            break;

            case 4:
            exit(0);
        }
          /* printf("\n\nDisplaying the arrray \n ");
           for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n"); */
  
   }
   return 0;
}
