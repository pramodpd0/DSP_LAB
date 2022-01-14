#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int* a, int p, int mid, int q)
{
    int n = mid-p+1, m = q - mid;
    int *a1 = (int*)malloc(sizeof(int)*n);
    int *a2 = (int*)malloc(sizeof(int)*m);

    int i, j, k;
    for(i = 0; i < n; i++)
        a1[i] = a[p + i];
    for(j = 0; j < m; j++)
        a2[j] = a[mid + 1 + j];

    j = 0; k = p; i = 0;

    while(i < n && j < m)
    {
        if(a1[i] > a2[j])
        {
            a[k++] = a2[j++];
        }
        else
        {
            a[k++] = a1[i++];
        }
    }
    while(i < n)
    {
        a[k++] = a1[i++];
    }
    while(j < m)
    {
        a[k++] = a2[j++];
    }
}
void mergesort(int * a, int p, int q)
{
    if(p < q)
    {
        int mid = (q+p)/2;
        mergesort(a, p, mid);
        mergesort(a, mid+1, q);
        merge(a, p, mid, q);
    }
}

int main()
{
    int n;
    printf("enter size of array\n");
    scanf("%d",&n);

    int* a = (int*)malloc(sizeof(int)*n);
    int i;
    for(i = 0; i < n; i++)
    {
        a[i] = rand()%1000000;
    }
    double t = 0.0;
    clock_t beg = clock();
    mergesort(a,0,n-1);
    clock_t end = clock();

    t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
    i = 0;
    while(i < n)
    printf("%d  ", a[i++]);
    printf("\ntotal time to sort elements of unsorted array :%f seconds \n", t);

    beg = clock();
    mergesort(a,0,n-1);
    end = clock();
    t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
    printf("\ntotal time to sort elements of sorted array :%f seconds \n", t);
    
    int k=0;
    while(k<n/4){
    a[2*k/3] = a[0];
    }

    beg = clock();
    mergesort(a,0,n-1);
    end = clock();
    t = (double)(end - beg) / (double)CLOCKS_PER_SEC;
    printf("\ntotal time to sort elements of almost sorted array :%f seconds \n", t);
    return 0;
}