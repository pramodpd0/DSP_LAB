#include <stdio.h>
#include <stdlib.h>
 
int top = -1;
char stack[100];
 
void push(char c)
{
   stack[++top]=c;
}
 
void pop()
{
   if(top==-1)
       printf("Invalid String\n");
   else
       top--;
}
 
int main()
{
   char str[100];
   printf("Enter string\n");
   scanf("%s",str);
 
   int i;
   for(i=0; str[i]!='\0'; i++)
   {
       if(str[i]=='(' || str[i]=='[' || str[i]=='{')
           push(str[i]);
       else
       {
           if(str[i]-stack[top]==1 || str[i]-stack[top]==2)
               pop();
           else
               break;
       }
   }
   if(top == -1)
       printf("valid String\n");
   else
       printf("Invalid String\n");
 
   return 0;
}

