/*
Implementation  Heap-sort Algorithm Using Min-Heapify and Max-Heapify
Procedures.
opt_1: 1) Using Max-heap
       2) Using Min-heap

opt_2: 1)Build-heap method
       2)Insertion
       3)Deletion
       4)Heap-Sort

*/

#include<stdio.h>
#include<stdlib.h>
#define m 100  // number of elements <= m+1

int arr[m]; 
int size=-1;  // size indicates number of elements in arr i.e size+1

// for swapping
void swap(int *a, int *b)
{
    int t = *a;
    *a=*b;
    *b=t;
}

// Max-heapify top approach
void max_ht(int p, int n)
{
   int c= 2*p+1;  // childs's index (p)

    if(n<=m)
    {
        if(arr[c]<= arr[c+1])
        {
         c+=1;
        }
        if((c<=n) && (arr[p]<arr[c]))
        {
            swap(&arr[p], &arr[c]);
            max_ht(c,n);
        }
    }
}

// Max-heapify bottom approach
void max_hb(int c)
{
    int p= (c-1)/2;  // parent's index (p)

    if((p>=0)&&(size<=m))
    {
        if(arr[p]<arr[c])
        {
            swap(&arr[p], &arr[c]);
            max_hb(p);
        }
    }
}

// Min-heapify top approach
void min_ht(int p,int n)
{
   int c= 2*p+1;   // child's index (p)

    if(n<=m) 
    {
        if(arr[c]>= arr[c+1])
        {
         c+=1;
        }
        if((c<=n) && (arr[p]>arr[c]))
        {
            swap(&arr[p], &arr[c]);
            min_ht(c,n);
        }
    }
}

// Min-heapify bottom approach
void min_hb(int c)
{
    int p= (c-1)/2;   // parent's index (p)

    if((p>=0)&&(size<=m))
    {
        if(arr[p]>arr[c])
        {
            swap(&arr[p], &arr[c]);
            min_hb(p);
        }
    }
}
// Build heap function , int x is option:  1 for max heap 2 for min-heap 
void build_heap(int x)
{

    if(size>m)
    {
        printf("Memory can not be allocated \n");
    }
    else{
    for(int i=(size-1)/2; i>=0; i--)
    {
        if(x==1)
        {
            max_ht(i,size); 
        }

        if(x==2)
        {
            min_ht(i,size);
        }
    }}
}

// insert function inserting the element and heapify 
void insert(int x)
{
    int val;
    if((size+1) > m)
    printf("Overflow problem \n");
    
    else{
    printf("Enter element \n");
    scanf("%d",&val);

    size++;
    arr[size]= val;
    
    if(x==1)
    {
        max_hb(size);
    }
    else
    {
        min_hb(size);
    }
    }
}

// Delete function basically delete max one & store in size variable
void delete(int x)
{
    if(size<=-1)
    {
        printf("No element  available to delete \n");
    }
    
    else{
    swap(&arr[0], &arr[size]);
    size--;

    if(x==1)
    {
        max_ht(0,size);
    }
    else if(x==2)
    {
        min_ht(0,size);
    }
    }
}

//Sorting function for sorting array using heap sort
void sort(int x)
{
  build_heap(x);

  for(int i=-1;i<=size;i++)
    {
        delete(x);
    }
}

// printing element
void display()
{
   
    if(size!= -1)    // if there is element then only print else do nothing
    {
        int i=0;
       printf("Elements are : \n");
        for(i=0;i<=m;i++)
        {
            if(arr[i]!=NULL)
            {
               printf("%d ", arr[i]);
            }
        }
        printf("\n");
    }
}

// main function body
int main()
{
    int opt1,opt2; 

    printf("\n Enter option \n1.\tMax-heapify\t\t2.\tMin-heapify \t\t3.\tExit \n");
    scanf("%d",&opt1); 
    
   // first for choosing either min-heap or max-heap
 while(1) 
    {
        switch(opt1)
        {
            case 1:
            {
                while(1)
                {
                 printf("Enter option \n1.\t Build heap\t\t2.\t Insertion\t\t3.\t Deletion\t\t4\t Sort\t\t5.\t Exit \n");
                 scanf("%d",&opt2);
                
                    switch(opt2)
                    {
                        case 1:
                        {   
                            int n,k;
                        
                            printf("How many numbers to Insert for build heap \n");
                            scanf("%d",&n);

                            if((n+size)>m)  // (n+size+1)>m+1)
                            printf("overflow problem \n");

                            else{

                            for(int i=0; i<n;i++)
                            {
                              printf("Enter element \n");
                             size++;
                             scanf("%d", &arr[(size)]);
                             }
                            build_heap(1);
                            }
                            break;
                        }
                        case 2:
                        {
                            insert(1);
                            break;
                        }
                        case 3:
                        {
                            delete(1);
                            break;
                        }
                        case 4:
                        {
                            sort(1);
                            break;
                        }
                        case 5:
                        {
                            exit (0);
                        }
                        default:
                        printf("invalid choice entered \n");
                    }
                 display();
                }
            
            }
            

            case 2:
            {
                while(1)
                {
                    printf("Enter option \n1.\t Build heap\t\t2.\t Insertion\t\t3.\t Deletion\t\t4\t Sort\t\t5.\t Exit\n");
                    scanf("%d",&opt2);
                    switch(opt2)
                    {
                        case 1:
                        {   
                            int n,k;
                            printf("How many numbers to Insert for build heap \n");
                            scanf("%d",&n);

                            if((n+size)>m) //(n+size+1)>m+1)
                            printf("overflow problem \n");

                            else{
                            for(int i=0; i<n;i++)
                            {
                              printf("Enter element \n");
                             size++;
                             scanf("%d", &arr[(size)]);
                             }
                            build_heap(2);
                            }
                            break;
                        }
                        case 2:
                        {
                            insert(2);
                            break;
                        }
                        case 3:
                        {
                            delete(2);
                            break;
                        }
                        case 4:
                        {
                            sort(2);
                            break;
                        }
                        case 5:
                        {
                            exit(0);
                        }
                        default:
                        printf("invalid choice entered \n");
                    }
                    display();
                }
             break;
            }

            case 3:
            exit(0);

        }
    } 
    return 0;
}