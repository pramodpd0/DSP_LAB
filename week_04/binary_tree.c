#include<stdio.h>
#include<stdlib.h>
#define count 10

struct bt_node
{
    struct bt_node* left;
    int data;
    struct bt_node* right;
};
typedef struct bt_node node;

node* new_node(int value)
{
    node* node = (struct bt_node*)malloc(sizeof(node));

    node->left = NULL;
    node->data = value;
    node->right = NULL;

    return node;
}


node* insert_left(node* node, int x)
{
    if(node==NULL)
    {
        node = new_node(x);
        return node;
    }
    else
    {
        return (node->left = insert_left(node->left , x));
    }
}

node* insert_right(node* node, int x)
{
    if(node==NULL)
    {
        node = new_node(x);
        return node;
    }
    else
    {
        return (node->right = insert_right(node->right , x));
    }
}

node* bt_creation(node* node ,int value)
{

    if(node==NULL)
    {
        return new_node(value);
        
    }
    else
    {
        int opt;
        printf("enter choice:\n\t\t1\t for inserting as left child"); 
        printf("\n\t\t2\t for inserting as right child \n");
        scanf("%d",&opt);

        if(opt==1)
        {
           node->left = bt_creation(node->left, value);
        } 
        else if(opt==2)
        {
            node->right = bt_creation(node->right, value);
        }
        else
        {
            printf("invalid choice entered \n");
            
        }
       return(node);
    }
}

int max(int a, int b)
{
    return(a>b?a:b);
}

int height(node* node)
{
    if(node==NULL)
    {
        return 0;
    }
  
    else 
    {
        return( 1 + max( height(node->left), height(node->right) ) );
    }
}

void preorder(node* node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);

    }
}

void inorder(node* node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);

    }
}

void postorder(node* node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);

    }
}

void display_tree(node* node, int space)
{
    int i;
    if(node==NULL)
    {
        return;
    }

    space+=count;

    display_tree(node->right, space);

    printf("\n\n");
    for(i=count;i<space;i++)
    {
        printf(" ");
    }
    printf("%d\n",node->data);

    display_tree(node->left, space);

}


int main()
{
    node* root =NULL;
    int choice;
    while(1)
    {
        printf("\nEnter choice  \n");
        printf("\t\t1\t create Binary tree\n\t\t2\t height of Binary tree\n");
        printf("\t\t3\t traversal of Binary tree\n\t\t4\t Display\n\t\t5\t exit\n");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int x; 
                printf("Enter node value \n");
                scanf("%d",&x);

                if(root==NULL)
                {
                   root =new_node(x);
                }
                else
                {
                    bt_creation(root,x);
                }

                break;
            }

            case 2:
            {
                printf("height of binary tree is: %d \n", height(root));

                break;
            }

            case 3:
            {
                printf("\nPreorder Traversal :");
                preorder(root);
                printf("\nInorder Traversal :");
                inorder(root);
                printf("\nPostorder Traversal :");
                postorder(root);

                break;
            }

            case 4:
            {
                display_tree(root,0);
  
                break;
            }

            case 5:
            {
                exit ;
            }

            default:
            {
                printf("Invalid input given \n");
            }

        }
        
    }

    return 0;
} 
