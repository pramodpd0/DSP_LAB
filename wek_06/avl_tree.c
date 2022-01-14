#include<stdio.h>
#include<stdlib.h>


struct avl
{
   struct avl* left;
   int data;
   struct avl* right;
   int ht;
} ;
typedef struct avl node;

node* root = NULL;

// new node creation
node* new_node(int value)
{
    node* node = (struct avl*)malloc(sizeof(struct avl));
    node-> left = NULL;
    node-> data = value;
    node-> right = NULL;
    node->ht= 1;

    return (node);  
} 

int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    return b;
}

int height(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    return head->ht;

}

int bal_fact(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
   return( height(head->left) - height(head->right) );    
    
}

node* right_rotate(node* node)
{
   struct avl* t1 = node->left;
   struct avl* t2 = t1->right;

    t1->right = node;
    node->left = t2;

    node->ht = 1 + max(height(node->left), height(node->right));
    t1->ht = 1 + max(height(t1->left), height(t1->right));

    return t1;
}

node* left_rotate(node* node)
{
    struct avl* t1= node->right;
    struct avl* t2= t1->left;

    t1->left = node;
    node->right = t2;

    node->ht = 1 + max(height(node->left), height(node->right));
    t1->ht = 1 + max(height(t1->left), height(t1->right));

    return t1;
}

// insertion x value in AVL tree 
node* insertion(node* head, int x)
{ 
   
    if(head == NULL)
    {
        return (new_node(x));
    }
   
    if(x < head->data)        // smaller than root data go left side  
    {
        head->left = insertion(head-> left,x);
    }
    

    else if(x> head->data)
    {
       head->right = insertion(head-> right, x);   //// larger than root data go right side  
    }
    
    else
    {
        printf("%d is already in tree, the elements should be unique in AVL tree \n",x);
        return head;
    }
    head->ht = 1 + max(height(head->left), height(head->right));

    int bf= bal_fact(head);
    
    if( bf>1 && (x < head->left->data ) )
    {
        return right_rotate(head);
    }

    if( bf<-1 && (x > head->right->data) )
    {
        return left_rotate(head);
    }

   if( bf>1 && (x > head->left->data) )
    {
        head->left = left_rotate(head->left);
        return(right_rotate(head));
    }

   if( bf<-1 && (x < head->right->data) )
    {
        head->right = right_rotate(head->right);
        return(left_rotate(head));
    }

    return head;
    
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

// deletion of element from AVL tree
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

    head->ht = 1 + max(height(head->left), height(head->right));

    int bf= bal_fact(head);
    
    if( bf>1 && (bal_fact(head->left)>= 0) )
    {
        return right_rotate(head);
    }

    if( bf<-1 && (bal_fact(head->right)<= 0) )
    {
        return left_rotate(head);
    }

   if( bf>1 && (bal_fact(head->left) < 0) )
    {
        head->left = left_rotate(head->left);
        return(right_rotate(head));
    }

   if( bf<-1 && (bal_fact(head->right) > 0) )
    {
        head->right = right_rotate(head->right);
        return(left_rotate(head));
    }

    return head;
}

void preorder(node* head)
{
    if(head!=NULL)
    {
        printf(" %d ",head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void inorder(node* head)
{
    if(head!=NULL)
    {
        inorder(head->left);
        printf(" %d ",head->data);
        inorder(head->right);
    }
}
void postorder(node* head)
{
    if(head!=NULL)
    {
        postorder(head->left);
        postorder(head->right);
        printf(" %d ",head->data);
    }
}

int sum_left(node* head)
{
    if(head==NULL)
    return 0;

    else
    {
      return(head->data + sum_left(head->left)+ sum_left(head->right));
    }
    
}

int main()
{
    int opt;
    
    while(1)
    {
    
        printf("\n Enter option : ");
        printf("\n\t1\t\t Insertion \n\t2\t\t Deletion \n\t3\t\t Display ");
        printf("\n\t4\t\t sum of  left subtree node \n\t5\t\t exit \n");
        scanf("%d", &opt);
        switch(opt)
        {
           case 1:
           {
                int x;
                printf("Enter data \n");
                scanf("%d",&x);
            
                root = insertion(root,x);
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
            {
                printf("\nPre order traversal : \n ");
                preorder(root);
                printf("\nInorder traversal : \n ");
                inorder(root);
                printf("\nPostorder traversal : \n ");
                postorder(root); 
                printf("\nLevel order traversal : \n ");
                bfs(root);

                break;

            }
           

            case 4:
            {
                printf("Sum of all nodes in left subtree of  root node: %d\n ",sum_left(root->left));
                
             
                break;
            }

            case 5:
            exit(0);

            default:
            printf("Enter valid option \n");
        }
    }
    
 return 0;
}
