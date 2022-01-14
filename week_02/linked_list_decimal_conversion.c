#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
typedef struct node
{
   int data;
   struct node* next;
} node;
 
node* head = NULL;
int n=0;
void insert_at_begin(int x)
{
   node* temp = (node*)malloc(sizeof(node));
   temp->data = x;
   temp->next = NULL;
   n++;
   if(head == NULL)
   {
       head= temp;
   }
   else{
       temp->next = head;
       head = temp;
   }
   temp = NULL;
   free(temp);
}
void insert_at_end(int x)
{
   node* temp = (node*)malloc(sizeof(node));
   temp->data = x;
   n++;
   if(head == NULL)
   {
       temp->next = NULL;
       head= temp;
   }
   else{
       node* it=head;
       while(it->next)
       {
           it = it->next;
       }
       it->next = temp;
       temp->next = NULL;
       it = NULL;
       free(it);
   }
   temp = NULL;
   free(temp);
}
void disp()
{
   long long int x=0;
   int i = n;
   node* it = head;
   if(it == NULL)
       printf("empty string\n");
 
   while(it != NULL)
   {
       x = x+it->data*pow(2,--i);
       it = it->next;
   }
   printf("%lld\n",x);
}
 
int main()
{
   int x,val;
 
   while(1)
   {
       printf("press \n 1 :for inserting the value at begin\n 2: for inserting element at end\n 3: to display the decimal value\n 4: for exit\n");
       scanf("%d",&x);
       if(x==4)
       {
           break;
       }
       else if(x==3)
       {
           disp();
       }
       else{
           printf("enter the value 0 or 1\n");
           scanf("%d",&val);
           if(val != 0 && val != 1)
           {
               printf("invalid input\n");
               continue;
           }
           if(x == 1)
               insert_at_begin(val);
           else
               insert_at_end(val);
           }
   }
   return 0;
}

