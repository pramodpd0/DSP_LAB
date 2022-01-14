/*
‌‌implement‌ing  ‌Binary‌ ‌Search‌ ‌Tree‌ 
insertion 
deletion
level order trversal
sum of all leaf nodes
sum of all non leaf nodes

*/

#include<stdio.h>
#include<stdlib.h>


struct bst
{
   struct bst* left;
   int data;
   struct bst* right;
} ;
typedef struct bst node;

 node* root = NULL;

// new node creation
node* new_node(int value)
{
    node* node = (struct bst*)malloc(sizeof(node));
    node-> left = NULL;
    node-> data = value;
    node-> right = NULL;
    return node;  
} 

// insertion x value in binary search tree 
node* insertion(node* head, int x)
{ 
   
    if(head == NULL)
    {
        return new_node(x);
    }
   
    if(x < head->data)        // smaller than root data go left side  
    {
        head->left = insertion(head-> left,x);
    }
    else if(x= head->data)
    {
        printf("%d is already in tree, the elements should be unique in binary search tree \n",x);
    }

    else 
    {
       head->right = insertion(head-> right, x);   //// larger than root data go right side  
    }
    
    return head;
    
}

// for calculating sum of all leaf nodes
int  sum_lf(node* root)
{
    int sum = 0;

    if(root == NULL)
    return 0;

    if((root->left == NULL) && (root->right==NULL))
    return sum += root->data;

    else
    {
        return (sum_lf(root->left) + sum_lf(root->right)); 
    }
}

// for calculating sum of all non-leaf nodes
int  sum_nlf(node* root)
{
    int sum = 0;

    if(root == NULL)
    return 0;

    if((root->left== NULL) && (root->right==NULL))
    return 0;
    else
    {
        return (root->data + sum_nlf(root->left) + sum_nlf(root->right)); 
    }
}

// height function for calculating from any node 
int height(node* root)
{
    if (root==NULL)
    return 0;

    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>= rh)
        return (1+ lh);
        else
        return (1+ rh);
    }

}

// printing element of level
void level_prnt(node* head ,int l)
{
    if(head== NULL)
    return ;

    if (l ==1)
    {
        printf(" %d ", head->data);
    }
    else if(l>1)
    {
      level_prnt(head->left,l-1);
      level_prnt(head->right ,l-1);
    }

}

// bfs (level-order traversal) print  using height and level
void bfs(node* head)
{
  int h = height(head);
  int i;
  for(i=1;i<=h;i++)
  {
      level_prnt(head,i);
  }

}

// finding  predecessor element to replace with "head" node
// we can also use succesor element instead of this
node* predecessor(node* head)
{
    if((head->left== NULL)&&(head->right == NULL))
    {
        return head;
    }
    else
    return predecessor(head->right);
}

// deletion of element from binary search tree
node* delete(node* head ,int x)
{
    if(head == NULL)
    return head;
 
    if(x < head->data)
    {
        head->left = delete(head->left,x);    // connecting node to left 
    }
    else if(x > head->data)
    {
        head->right = delete(head->right,x);   // connecting node to right
    }
    
    else                                    // when x== head->data
    {
        if(head->left == NULL)
        {
            node* temp = head->right;       
            free(head);

            return (temp);                  // connecting temp node to parent node of head
        }
        else if(head->right == NULL)      
        {
            node* temp = head->left;
            free(head);

            return (temp);                   // connecting temp node to parent node of head
        }

        node* temp = predecessor(head->left); // maximum value element in left subtree of head node
        head-> data = temp->data;             // storing that value to head->data

        head->left = delete(head->left ,temp->data);  // then delet that maximum value element node from tree
    }

    return head;

}

int main()
{
    int opt;
    
    while(1)
    {
    
        printf("\n Enter option : ");
        printf("\n\t1\t\t Insertion \n\t2\t\t Deletion \n\t3\t\t level order traversal");
        printf("\n\t4\t\t sum of all leaf node \n\t5\t\t sum of all non leaf node \n\t6\t\t exit \n");
        scanf("%d", &opt);
        switch(opt)
        {
           case 1:
           {
                int x;
                printf("Enter data \n");
                scanf("%d",&x);
               if(root == NULL)
               {
                   root = insertion(root,x);
               }
               else
               {
                    insertion(root,x);
               }
            
             break;
           }

           case 2:
           {
              int x;
              if(root==NULL)
              {
                  printf("tree is empty can not perform deletion\n");
              }
              else{
              printf("Enter number to delete \n");
              scanf("%d",&x);
              delete(root,x);
              }
              break;
           }
           

            case 3:
            printf("Level order traversal : \n ");
            bfs(root);
            break;

            case 4:
             if(root==NULL)
              {
                  printf("tree is empty \n");
              }
              else
              {
                    printf("sum of leaf nodes %d \n ",sum_lf(root));
              }
            break;

            case 5:
              if(root==NULL)
              {
                  printf("tree is empty \n");
              }
              else
              {
                 printf("sum of Non-leaf nodes %d \n ",sum_nlf(root));
              }
            break;

            case 6:
            exit(0);

            default:
            printf("Enter valid option \n");
        }
    }
    
 return 0;
}
