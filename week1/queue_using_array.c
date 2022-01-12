#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int size;
    int f;
    int r;
    int* arr;
}queue;

int is_full(queue* q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}
int is_empty(queue* q)
{
    if(q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val)
{
    if(is_full(q))
    {
        printf("Queue is full \n");
    }

    else
    {
        q->r++;
        q->arr[q->r]= val;
    }
}


int dequeue(queue*q)
{
    int x;
    if(is_empty(q))
    {
        printf("Queue is Empty \n");
    }
    else
    {
        q->f++;
        x = q->arr[q->f];
    }
    return x;
    
}

int main()
{
    queue q;
    q.size =100;
    q.f=-1;
    q.r=-1;

    q.arr = (int*)malloc(sizeof(int)*q.size);

    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    printf("\nDequeuing element %d ",dequeue(&q));
    printf("\nDequeuing element %d ",dequeue(&q));

    return 0; 


}




