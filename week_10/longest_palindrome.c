/*
  Finding longest palindrome in string
   
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 50  


char str[max];

// helper function for finding minimum
int min(int a,int b)
{
    return(a<=b?a:b);
}

// return index of array which have larger value
int max_value(int* a, int size)
{
    int len=0;
    int l=0;
    for(int i=0;i<size;i++)
    {
        if(len <= a[i])
        {
           len = a[i];
           l=i;
        }
        
    }
    return l;
}

// function to print longest pallindrome 
void palindrome_string(char* arr, int size)
{
   
    int i,c,r,mirr,l; 

    // taking an integer array for storing lenght of pallindrome assuming center at every value
    int p[size];

    for(i=0;i<size;i++)
    {
        p[i]=0;
    }
    c=0;
    r=0;
    
    for(i=1;i<size;i++)
    {
        mirr= 2*c-i;
        
        // using pallindrome property
        if(i<r)
        {
            p[i]= min(r-i, p[mirr]);
        }
       
        // incrementin p[i] value if satisfy the condition 
        while(arr[1+(i+p[i])] == arr[(i-p[i])-1])
        {
            p[i]++;
        }
        
        if(i+p[i] > r)
        {
            c=i;
            r=i+p[i];
        }
    }
    p[1]++;
   
   // getting index l of array p which is also centre of longest palindrome 
    l= max_value(p,size);

    // printing longest palindrome
    i=l-p[l];
    if(i%2==0)
    {
        i++;
    }
    while(i<= l+p[l])
    {
        printf("%c",arr[i]);
        i+=2;
    }
  
} 

//driver program
int main()
{
    int i,j; 
    int size=0;
    
    printf("Enter Strings \n");
    scanf("%s",str);
    size = 2*strlen(str)+1;
    char arr[size];

    // inserting '#' between characters, '@' at starting index, and '&' at ending index 
    j=0;
    arr[j]='@';
    for(i=0;i<strlen(str);i++)
    {
        j++;
        arr[j]= str[i];

        j++;
        arr[j]='#';
       
    }
    arr[j]='$';

    printf("\nLongest palindrome in this string:\t");
    palindrome_string(arr,size);

    return 0;
}
