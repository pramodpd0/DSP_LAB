/*
Hash table for integers 
(using collision technique : Quadratic Probing)
1.Insert a Key
2. Delete a Key
3. Search a Key Using key Value
4. Calculate Load Factor

*/
/*
 constraints:
    10<=m
    1<= key<= 10^9
 
*/

#include<stdio.h>
#include<stdlib.h>
#define m 20      // slots number in hash table (bucket) from 0 to m-1

int ht[m];         // hash table of size m for storing integer value(key) 

// taking int n to count number of elements available in hash table
int n=0;

/* Using Quadratic probing collision resolution technique 
 'qp' returns slot number for storing key value  */
int QP(int key, int i)
{
    int c1=1;
    int c2=1;
    int hf_key = key%m;
    int qp= (hf_key + c1*i + c2*(i*i))% m;
    return qp;
}

// insertion of key 
void insert()
{
    int key, index ,i;
    printf("Enter value \n");
    scanf("%d", &key);
    for(i=0;i<m;i++)
    {
        index = QP(key,i);
        if(ht[index]== NULL)  
        {
            ht[index] =key;
            n+=1;       //increasing key value
            break;
        } 
    }

    if(i==m)   // no slots are empty
       printf("value can not be entered \n");  
}

// searching element (key) if present then return its slot number.
void search()
{
    int key ,index ,i;
    printf("enter value to search \n");
    scanf("%d", &key);
    for(i=0;i<m;i++)
    {
        index = QP(key,i);
        if(ht[index]== key)
        {
            printf("value is found at index %d \n",index);
            break;
        }   
    }

    if(i == m) 
    printf("\nelement is not found\n");
}

// printing the hash table and all keys with thier index
void display()
{
    int i;
    printf("\n elements in the hash table are : \n");
    for(i=0;i<m;i++)
    {
        printf(" at index %d \t value =  %d \n",i,ht[i]);
    }
}

// delete the key i.e. make index value null
void delete()
{
    int key, index;
    printf("\n Enter element \n");
    scanf("%d",&key);
    int i;
    for(i=0;i<m;i++)
    {
        index =QP(key,i);
        if(ht[index]== key)
        {
            printf("\n Element %d is at index %d  is deleted. \n", key,index);
            ht[index] = NULL;
            n-=1;               // decreasing n value
            break; 
        }
    }
    if(i==m)
    printf("Element is not in the hash table \n");
}

/* calculating load factor :
   (number of keys present in hash table / total number of slots)  */
void load_fact()
{
    double lf = (double)n/m;
    printf("\n load factor: %f", lf);
    
}

int main()
{
    int opt;
    
    while(1)
    {
        printf("\nPress 1. Insert\t2. Search \t3.delete \t4. load factor \t5.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
                
            case 2:
                search();
                break;
            case 3:
                delete();
                break;
            case 4:
                load_fact();
                break;
            case 5:exit(0);
            
            default:
             printf("invalid choice entered \n");
        }
        display();
    }

    return 0;
}
